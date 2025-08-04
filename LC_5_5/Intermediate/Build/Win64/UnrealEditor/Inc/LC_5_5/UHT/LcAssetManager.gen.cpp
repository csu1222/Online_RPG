// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/System/LcAssetManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcAssetManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAssetManager();
LC_5_5_API UClass* Z_Construct_UClass_ULcAssetManager();
LC_5_5_API UClass* Z_Construct_UClass_ULcAssetManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcAssetManager
void ULcAssetManager::StaticRegisterNativesULcAssetManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcAssetManager);
UClass* Z_Construct_UClass_ULcAssetManager_NoRegister()
{
	return ULcAssetManager::StaticClass();
}
struct Z_Construct_UClass_ULcAssetManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/LcAssetManager.h" },
		{ "ModuleRelativePath", "System/LcAssetManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcAssetManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULcAssetManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetManager,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcAssetManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcAssetManager_Statics::ClassParams = {
	&ULcAssetManager::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcAssetManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcAssetManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcAssetManager()
{
	if (!Z_Registration_Info_UClass_ULcAssetManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcAssetManager.OuterSingleton, Z_Construct_UClass_ULcAssetManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcAssetManager.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcAssetManager>()
{
	return ULcAssetManager::StaticClass();
}
ULcAssetManager::ULcAssetManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcAssetManager);
ULcAssetManager::~ULcAssetManager() {}
// End Class ULcAssetManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcAssetManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcAssetManager, ULcAssetManager::StaticClass, TEXT("ULcAssetManager"), &Z_Registration_Info_UClass_ULcAssetManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcAssetManager), 854837514U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcAssetManager_h_996347174(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcAssetManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcAssetManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
