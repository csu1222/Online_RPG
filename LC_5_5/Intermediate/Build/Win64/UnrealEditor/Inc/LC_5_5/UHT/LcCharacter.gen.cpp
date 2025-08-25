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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_ALcCharacter, ALcCharacter::StaticClass, TEXT("ALcCharacter"), &Z_Registration_Info_UClass_ALcCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcCharacter), 2860055932U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_1670612127(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
