// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Player/LcPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerController();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcPlayerController
void ALcPlayerController::StaticRegisterNativesALcPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcPlayerController);
UClass* Z_Construct_UClass_ALcPlayerController_NoRegister()
{
	return ALcPlayerController::StaticClass();
}
struct Z_Construct_UClass_ALcPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Player/LcPlayerController.h" },
		{ "ModuleRelativePath", "Player/LcPlayerController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALcPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcPlayerController_Statics::ClassParams = {
	&ALcPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcPlayerController()
{
	if (!Z_Registration_Info_UClass_ALcPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcPlayerController.OuterSingleton, Z_Construct_UClass_ALcPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcPlayerController.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcPlayerController>()
{
	return ALcPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcPlayerController);
ALcPlayerController::~ALcPlayerController() {}
// End Class ALcPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcPlayerController, ALcPlayerController::StaticClass, TEXT("ALcPlayerController"), &Z_Registration_Info_UClass_ALcPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcPlayerController), 858039383U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerController_h_1176297713(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
