// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Character/LcCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
LC_5_5_API UClass* Z_Construct_UClass_ALcCharacter();
LC_5_5_API UClass* Z_Construct_UClass_ALcCharacter_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraComponent_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnExtensionComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcCharacter
void ALcCharacter::StaticRegisterNativesALcCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcCharacter);
UClass* Z_Construct_UClass_ALcCharacter_NoRegister()
{
	return ALcCharacter::StaticClass();
}
struct Z_Construct_UClass_ALcCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/LcCharacter.h" },
		{ "ModuleRelativePath", "Character/LcCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnExtComponent_MetaData[] = {
		{ "Category", "LC|Chacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/LcCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[] = {
		{ "Category", "LC|Chacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/LcCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PawnExtComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALcCharacter_Statics::NewProp_PawnExtComponent = { "PawnExtComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALcCharacter, PawnExtComponent), Z_Construct_UClass_ULcPawnExtensionComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnExtComponent_MetaData), NewProp_PawnExtComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALcCharacter_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALcCharacter, CameraComponent), Z_Construct_UClass_ULcCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraComponent_MetaData), NewProp_CameraComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALcCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALcCharacter_Statics::NewProp_PawnExtComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALcCharacter_Statics::NewProp_CameraComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALcCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcCharacter_Statics::ClassParams = {
	&ALcCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ALcCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ALcCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcCharacter()
{
	if (!Z_Registration_Info_UClass_ALcCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcCharacter.OuterSingleton, Z_Construct_UClass_ALcCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcCharacter.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcCharacter>()
{
	return ALcCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcCharacter);
ALcCharacter::~ALcCharacter() {}
// End Class ALcCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcCharacter, ALcCharacter::StaticClass, TEXT("ALcCharacter"), &Z_Registration_Info_UClass_ALcCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcCharacter), 2334804743U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_3014772140(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
