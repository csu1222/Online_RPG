// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Input/LcInputConfig.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcInputConfig() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
LC_5_5_API UClass* Z_Construct_UClass_ULcInputConfig();
LC_5_5_API UClass* Z_Construct_UClass_ULcInputConfig_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcInputConfig
void ULcInputConfig::StaticRegisterNativesULcInputConfig()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcInputConfig);
UClass* Z_Construct_UClass_ULcInputConfig_NoRegister()
{
	return ULcInputConfig::StaticClass();
}
struct Z_Construct_UClass_ULcInputConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Input/LcInputConfig.h" },
		{ "ModuleRelativePath", "Input/LcInputConfig.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcInputConfig>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULcInputConfig_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcInputConfig_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcInputConfig_Statics::ClassParams = {
	&ULcInputConfig::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcInputConfig_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcInputConfig_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcInputConfig()
{
	if (!Z_Registration_Info_UClass_ULcInputConfig.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcInputConfig.OuterSingleton, Z_Construct_UClass_ULcInputConfig_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcInputConfig.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcInputConfig>()
{
	return ULcInputConfig::StaticClass();
}
ULcInputConfig::ULcInputConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcInputConfig);
ULcInputConfig::~ULcInputConfig() {}
// End Class ULcInputConfig

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputConfig_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcInputConfig, ULcInputConfig::StaticClass, TEXT("ULcInputConfig"), &Z_Registration_Info_UClass_ULcInputConfig, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcInputConfig), 3232074313U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputConfig_h_2914423701(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputConfig_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputConfig_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
