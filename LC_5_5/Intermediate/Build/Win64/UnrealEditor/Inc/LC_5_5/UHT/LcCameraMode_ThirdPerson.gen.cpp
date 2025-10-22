// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Camera/LcCameraMode_ThirdPerson.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcCameraMode_ThirdPerson() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UCurveVector_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode_ThirdPerson();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode_ThirdPerson_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcCameraMode_ThirdPerson
void ULcCameraMode_ThirdPerson::StaticRegisterNativesULcCameraMode_ThirdPerson()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcCameraMode_ThirdPerson);
UClass* Z_Construct_UClass_ULcCameraMode_ThirdPerson_NoRegister()
{
	return ULcCameraMode_ThirdPerson::StaticClass();
}
struct Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Camera/LcCameraMode_ThirdPerson.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Camera/LcCameraMode_ThirdPerson.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetOffsetCurve_MetaData[] = {
		{ "Category", "Third Person" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* member variables\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode_ThirdPerson.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "member variables" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetOffsetCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcCameraMode_ThirdPerson>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::NewProp_TargetOffsetCurve = { "TargetOffsetCurve", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode_ThirdPerson, TargetOffsetCurve), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetOffsetCurve_MetaData), NewProp_TargetOffsetCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::NewProp_TargetOffsetCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULcCameraMode,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::ClassParams = {
	&ULcCameraMode_ThirdPerson::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::PropPointers),
	0,
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcCameraMode_ThirdPerson()
{
	if (!Z_Registration_Info_UClass_ULcCameraMode_ThirdPerson.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcCameraMode_ThirdPerson.OuterSingleton, Z_Construct_UClass_ULcCameraMode_ThirdPerson_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcCameraMode_ThirdPerson.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcCameraMode_ThirdPerson>()
{
	return ULcCameraMode_ThirdPerson::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcCameraMode_ThirdPerson);
ULcCameraMode_ThirdPerson::~ULcCameraMode_ThirdPerson() {}
// End Class ULcCameraMode_ThirdPerson

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcCameraMode_ThirdPerson, ULcCameraMode_ThirdPerson::StaticClass, TEXT("ULcCameraMode_ThirdPerson"), &Z_Registration_Info_UClass_ULcCameraMode_ThirdPerson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcCameraMode_ThirdPerson), 3572415415U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_4188259477(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
