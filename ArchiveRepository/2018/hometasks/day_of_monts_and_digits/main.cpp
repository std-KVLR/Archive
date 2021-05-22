alRectangleNode *createInternalRectangleNode() = 0;
    virtual QSGInternalImageNode *createInternalImageNode() = 0;
    virtual QSGPainterNode *createPainterNode(QQuickPaintedItem *item) = 0;
    virtual QSGGlyphNode *createGlyphNode(QSGRenderContext *rc, bool preferNativeGlyphNode) = 0;
    virtual QSGLayer *createLayer(QSGRenderContext *renderContext) = 0;
    virtual QSGGuiThreadShaderEffectManager *createGuiThreadShaderEffectManager();
    virtual QSGShaderEffectNode *createShaderEffectNode(QSGRenderContext *renderContext,
                                                        QSGGuiThreadShaderEffectManager *mgr);
#if QT_CONFIG(quick_sprite)
    virtual QSGSpriteNode *createSpriteNode() = 0;
#endif
    virtual QAnimationDriver *createAnimationDriver(QObject *parent);

    virtual QSize minimumFBOSize() const;
    virtual QSurfaceFormat defaultSurfaceFormat() const = 0;

    virtual QSGRendererInterface *rendererInterface(QSGRenderContext *renderContext);

    virtual QSGRectangleNode *createRectangleNode() = 0;
    virtual QSGImageNode *createImage