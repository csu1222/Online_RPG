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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcCameraMode_ThirdPerson>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_ULcCameraMode_ThirdPerson, ULcCameraMode_ThirdPerson::StaticClass, TEXT("ULcCameraMode_ThirdPerson"), &Z_Registration_Info_UClass_ULcCameraMode_ThirdPerson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcCameraMode_ThirdPerson), 2218111710U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_3838333845(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_ThirdPerson_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
