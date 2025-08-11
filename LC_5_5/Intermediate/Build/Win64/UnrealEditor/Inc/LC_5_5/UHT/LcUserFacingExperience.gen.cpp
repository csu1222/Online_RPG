// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/GameModes/LcUserFacingExperience.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcUserFacingExperience() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
LC_5_5_API UClass* Z_Construct_UClass_ULcUserFacingExperience();
LC_5_5_API UClass* Z_Construct_UClass_ULcUserFacingExperience_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcUserFacingExperience
void ULcUserFacingExperience::StaticRegisterNativesULcUserFacingExperience()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcUserFacingExperience);
UClass* Z_Construct_UClass_ULcUserFacingExperience_NoRegister()
{
	return ULcUserFacingExperience::StaticClass();
}
struct Z_Construct_UClass_ULcUserFacingExperience_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GameModes/LcUserFacingExperience.h" },
		{ "ModuleRelativePath", "GameModes/LcUserFacingExperience.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapID_MetaData[] = {
		{ "AllowedTypes", "Map" },
		{ "Category", "Experience" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** the specific map to load */" },
#endif
		{ "ModuleRelativePath", "GameModes/LcUserFacingExperience.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "the specific map to load" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceID_MetaData[] = {
		{ "AllowedTypes", "HakExperienceDefinition" },
		{ "Category", "Experience" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** the gameplay expierence to load */" },
#endif
		{ "ModuleRelativePath", "GameModes/LcUserFacingExperience.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "the gameplay expierence to load" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MapID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExperienceID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcUserFacingExperience>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULcUserFacingExperience_Statics::NewProp_MapID = { "MapID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcUserFacingExperience, MapID), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapID_MetaData), NewProp_MapID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULcUserFacingExperience_Statics::NewProp_ExperienceID = { "ExperienceID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcUserFacingExperience, ExperienceID), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceID_MetaData), NewProp_ExperienceID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcUserFacingExperience_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcUserFacingExperience_Statics::NewProp_MapID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcUserFacingExperience_Statics::NewProp_ExperienceID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcUserFacingExperience_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcUserFacingExperience_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcUserFacingExperience_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcUserFacingExperience_Statics::ClassParams = {
	&ULcUserFacingExperience::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcUserFacingExperience_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcUserFacingExperience_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcUserFacingExperience_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcUserFacingExperience_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcUserFacingExperience()
{
	if (!Z_Registration_Info_UClass_ULcUserFacingExperience.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcUserFacingExperience.OuterSingleton, Z_Construct_UClass_ULcUserFacingExperience_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcUserFacingExperience.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcUserFacingExperience>()
{
	return ULcUserFacingExperience::StaticClass();
}
ULcUserFacingExperience::ULcUserFacingExperience(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcUserFacingExperience);
ULcUserFacingExperience::~ULcUserFacingExperience() {}
// End Class ULcUserFacingExperience

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcUserFacingExperience_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcUserFacingExperience, ULcUserFacingExperience::StaticClass, TEXT("ULcUserFacingExperience"), &Z_Registration_Info_UClass_ULcUserFacingExperience, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcUserFacingExperience), 4156822550U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcUserFacingExperience_h_4147731001(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcUserFacingExperience_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcUserFacingExperience_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
