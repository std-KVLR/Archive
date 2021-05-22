
 \
	DECLARE_FUNCTION(execSetFloatParameter) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ParameterName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetFloatParameter(Z_Param_ParameterName,Z_Param_Param); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEmitterEnable) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_EmitterName); \
		P_GET_UBOOL(Z_Param_bNewEnableState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetEmitterEnable(Z_Param_EmitterName,Z_Param_bNewEnableState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamTargetStrength) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TargetIndex); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutTargetStrength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamTargetStrength(Z_Param_EmitterIndex,Z_Param_TargetIndex,Z_Param_Out_OutTargetStrength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamTargetTangent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TargetIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutTangentPoint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamTargetTangent(Z_Param_EmitterIndex,Z_Param_TargetIndex,Z_Param_Out_OutTangentPoint); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamTargetPoint) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_TargetIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutTargetPoint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamTargetPoint(Z_Param_EmitterIndex,Z_Param_TargetIndex,Z_Param_Out_OutTargetPoint); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamSourceStrength) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SourceIndex); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutSourceStrength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamSourceStrength(Z_Param_EmitterIndex,Z_Param_SourceIndex,Z_Param_Out_OutSourceStrength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamSourceTangent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SourceIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutTangentPoint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamSourceTangent(Z_Param_EmitterIndex,Z_Param_SourceIndex,Z_Param_Out_OutTangentPoint); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamSourcePoint) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SourceIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutSourcePoint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamSourcePoint(Z_Param_EmitterIndex,Z_Param_SourceIndex,Z_Param_Out_OutSourcePoint); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBeamEndPoint) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_EmitterIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutEndPoint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetBeamEndPoint(Z_Param_EmitterIndex,Z_Param_Out_OutEndPoint); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBeamTa