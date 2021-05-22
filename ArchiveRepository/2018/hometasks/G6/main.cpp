 dsLayout;
    layoutCreateInfo.pushConstantRangeCount = 0;
    layoutCreateInfo.pPushConstantRanges = nullptr;

    VkResult err = GR_VK_CALL(gpu->vkInterface(), CreatePipelineLayout(gpu->device(),
                                                                       &layoutCreateInfo,
                                                                       nullptr,
                                                                       &fPipelineLayout));
    if (err) {
        this->destroyResources(gpu);
        return false;
    }

    static const float vdata[] = {
        0, 0,
        0, 1,
        1, 0,
        1, 1
    };
    fVertexBuffer.reset(GrVkVertexBuffer::Create(gpu, sizeof(vdata), false));
    SkASSERT(fVertexBuffer.get());
    fVertexBuffer->updateData(vdata, sizeof(vdata));

    // We use 2 vec4's for uniforms
    fUniformBuffer.reset(GrVkUniformBuffer::Create(gpu, 8 * sizeof(float)));
    SkASSERT(fUniformBuffer.get());

    return true;
}

bool GrVkCopyManager::copySurfaceAsDraw(GrVkGpu* gpu,
                                        GrSurface* dst,
                                        GrSurface* src,
                                        const SkIRect& srcRect,
                                        const SkIPoint& dstPoint) {
    // None of our copy methods can handle a swizzle. TODO: Make copySurfaceAsDraw handle the
    // swizzle.
    if (gpu->caps()->shaderCaps()->configOutputSwizzle(src->config()) !=
        gpu->caps()->shaderCaps()->configOutputSwizzle(dst->config())) {
        return false;
    }

    if (!gpu->vkCaps().supportsCopiesAsDraws()) {
        return false;
    }

    if (gpu->vkCaps().newCBOnPipelineChange()) {
        // We bind a new pipeline here for the copy so we must start a new command buffer.
        gpu->finishFlush();
    }

    GrVkRenderTarget* rt = static_cast<GrVkRenderTarget*>(dst->asRenderTarget());
    if (!rt) {
        return false;
    }

    GrVkTexture* srcTex = static_cast<GrVkTexture*>(src->asTexture());
    if (!srcTex) {
        return false;
    }

    if (VK_NULL_HANDLE == fVertShaderModule) {
        SkASSERT(VK_NULL_HANDLE == fFragShaderModule &&
                 VK_NULL_HANDLE == fPipelineLayout &&
                 nullptr == fVertexBuffer.get() &&
                 nullptr == fUniformBuffer.get());
        if (!this->createCopyProgram(gpu)) {
            SkDebugf("Failed to create copy program.\n");
            return false;
        }
    }

    GrVkResourceProvider& resourceProv = gpu->resourceProvider();

    GrVkCopyPipeline* pipeline = resourceProv.findOrCreateCopyPipeline(rt,
                                                                       fShaderStageInfo,
                                                                       fPipelineLayout);
    if (!pipeline) {
        return false;
    }

    // UPDATE UNIFORM DESCRIPTOR SET
    int w = srcRect.width();
    int h = srcRect.height();

    // dst rect edges in NDC (-1 to 1)
    int dw = dst->width();
    int dh = dst->height();
    float dx0 = 2.f * dstPoint.fX / dw - 1.f;
    float dx1 = 2.f * (dstPoint.fX + w) / dw - 1.f;
    float dy0 = 2.f * dstPoint.fY / dh - 1.f;
    float dy1 = 2.f * (dstPoint.fY + h) / dh - 1.f;
    if (kBottomLeft_GrSurfaceOrigin == dst->origin()) {
        dy0 = -dy0;
        dy1 = -dy1;
    }


    float sx0 = (float)srcRect.fLeft;
    float sx1 = (float)(srcRect.fLeft + w);
    float sy0 = (float)srcRect.fTop;
    float sy1 = (float)(srcRect.fTop + h);
    int sh = src->height();
    if (kBottomLeft_GrSurfaceOrigin == src->origin()) {
        sy0 = sh - sy0;
        sy1 = sh - sy1;
    }
    // src rect edges in normalized texture space (0 to 1).
    int sw = src->width();
    sx0 /= sw;
    sx1 /= sw;
    sy0 /= sh;
    sy1 /= sh;

    float uniData[] = { dx1 - dx0, dy1 - dy0, dx0, dy0,    // posXform
                        sx1 - sx0, sy1 - sy0, sx0, sy0 };  // texCoordXform

    fUniformBuffer->updateData(gpu, uniData, sizeof(uniData), nullptr);

    const GrVkDescriptorSet* uniformDS = resourceProv.getUniformDescriptorSet();
    SkASSERT(uniformDS);

    VkDescriptorBufferInfo uniBufferInfo;
    uniBufferInfo.buffer = fUniformBuffer->buffer();
    uniBufferInfo.offset = fUniformBuffer->offset();
    uniBufferInfo.range = fUniformBuffer->size();

    VkWriteDescriptorSet descriptorWrites;
    descriptorWrites.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    descriptorWrites.pNext