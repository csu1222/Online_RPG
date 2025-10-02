// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Character/LcPawnData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcPawnData() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnData();
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnData_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcPawnData
void ULcPawnData::StaticRegisterNativesULcPawnData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcPawnData);
UClass* Z_Construct_UClass_ULcPawnData_NoRegister()
{
	return ULcPawnData::StaticClass();
}
struct Z_Construct_UClass_ULcPawnData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Character/LcPawnData.h" },
		{ "ModuleRelativePath", "Character/LcPawnData.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnClass_MetaData[] = {
		{ "Category", "Lc|Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pawn\xec\x9d\x98 Class */" },
#endif
		{ "ModuleRelativePath", "Character/LcPawnData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pawn\xec\x9d\x98 Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCameraMode_MetaData[] = {
		{ "Category", "Lc|Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "///* Camera Mode */\n" },
#endif
		{ "ModuleRelativePath", "Character/LcPawnData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Mode" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_PawnClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultCameraMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcPawnData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULcPawnData_Statics::NewProp_PawnClass = { "PawnClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcPawnData, PawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnClass_MetaData), NewProp_PawnClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULcPawnData_Statics::NewProp_DefaultCameraMode = { "DefaultCameraMode", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcPawnData, DefaultCameraMode), Z_Construct_UClass_UClass, Z_Construct_UClass_ULcCameraMode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCameraMode_MetaData), NewProp_DefaultCameraMode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcPawnData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcPawnData_Statics::NewProp_PawnClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcPawnData_Statics::NewProp_DefaultCameraMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcPawnData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcPawnData_Statics::ClassParams = {
	&ULcPawnData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcPawnData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnData_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcPawnData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcPawnData()
{
	if (!Z_Registration_Info_UClass_ULcPawnData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcPawnData.OuterSingleton, Z_Construct_UClass_ULcPawnData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcPawnData.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcPawnData>()
{
	return ULcPawnData::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcPawnData);
ULcPawnData::~ULcPawnData() {}
// End Class ULcPawnData

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcPawnData, ULcPawnData::StaticClass, TEXT("ULcPawnData"), &Z_Registration_Info_UClass_ULcPawnData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcPawnData), 1464555721U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnData_h_2400186972(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
