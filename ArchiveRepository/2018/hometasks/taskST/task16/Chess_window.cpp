public:


#define Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWorldSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWorldSettings(AWorldSettings&&); \
	NO_API AWorldSettings(const AWorldSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWorldSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWorldSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWorldSettings)


#define Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AssetUserData() { return STRUCT_OFFSET(AWorldSettings, AssetUserData); }


#define Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_277_PROLOG
#define Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_INCLASS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_GameFramework_WorldSettings_h_280_PRIVA