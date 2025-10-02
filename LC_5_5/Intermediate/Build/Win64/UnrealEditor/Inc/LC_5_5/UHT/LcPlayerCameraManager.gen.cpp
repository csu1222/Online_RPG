// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Camera/LcPlayerCameraManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcPlayerCameraManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerCameraManager();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcPlayerCameraManager
void ALcPlayerCameraManager::StaticRegisterNativesALcPlayerCameraManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcPlayerCameraManager);
UClass* Z_Construct_UClass_ALcPlayerCameraManager_NoRegister()
{
	return ALcPlayerCameraManager::StaticClass();
}
struct Z_Construct_UClass_ALcPlayerCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Camera/LcPlayerCameraManager.h" },
		{ "ModuleRelativePath", "Camera/LcPlayerCameraManager.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcPlayerCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALcPlayerCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcPlayerCameraManager_Statics::ClassParams = {
	&ALcPlayerCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcPlayerCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcPlayerCameraManager()
{
	if (!Z_Registration_Info_UClass_ALcPlayerCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcPlayerCameraManager.OuterSingleton, Z_Construct_UClass_ALcPlayerCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcPlayerCameraManager.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcPlayerCameraManager>()
{
	return ALcPlayerCameraManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcPlayerCameraManager);
ALcPlayerCameraManager::~ALcPlayerCameraManager() {}
// End Class ALcPlayerCameraManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcPlayerCameraManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcPlayerCameraManager, ALcPlayerCameraManager::StaticClass, TEXT("ALcPlayerCameraManager"), &Z_Registration_Info_UClass_ALcPlayerCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcPlayerCameraManager), 3928948526U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcPlayerCameraManager_h_551369466(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcPlayerCameraManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcPlayerCameraManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
