// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1/A1AIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1AIController() {}

// Begin Cross Module References
A1_API UClass* Z_Construct_UClass_AA1AIController();
A1_API UClass* Z_Construct_UClass_AA1AIController_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
UPackage* Z_Construct_UPackage__Script_A1();
// End Cross Module References

// Begin Class AA1AIController
void AA1AIController::StaticRegisterNativesAA1AIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AA1AIController);
UClass* Z_Construct_UClass_AA1AIController_NoRegister()
{
	return AA1AIController::StaticClass();
}
struct Z_Construct_UClass_AA1AIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "A1AIController.h" },
		{ "ModuleRelativePath", "A1AIController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA1AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AA1AIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_A1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA1AIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AA1AIController_Statics::ClassParams = {
	&AA1AIController::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA1AIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AA1AIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AA1AIController()
{
	if (!Z_Registration_Info_UClass_AA1AIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AA1AIController.OuterSingleton, Z_Construct_UClass_AA1AIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AA1AIController.OuterSingleton;
}
template<> A1_API UClass* StaticClass<AA1AIController>()
{
	return AA1AIController::StaticClass();
}
AA1AIController::AA1AIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AA1AIController);
AA1AIController::~AA1AIController() {}
// End Class AA1AIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AA1AIController, AA1AIController::StaticClass, TEXT("AA1AIController"), &Z_Registration_Info_UClass_AA1AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AA1AIController), 2252133412U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_1244634981(TEXT("/Script/A1"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
