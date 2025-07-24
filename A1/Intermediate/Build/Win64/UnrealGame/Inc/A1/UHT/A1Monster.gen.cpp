// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1/Game/A1Monster.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1Monster() {}

// Begin Cross Module References
A1_API UClass* Z_Construct_UClass_AA1Monster();
A1_API UClass* Z_Construct_UClass_AA1Monster_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_A1();
// End Cross Module References

// Begin Class AA1Monster
void AA1Monster::StaticRegisterNativesAA1Monster()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AA1Monster);
UClass* Z_Construct_UClass_AA1Monster_NoRegister()
{
	return AA1Monster::StaticClass();
}
struct Z_Construct_UClass_AA1Monster_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/A1Monster.h" },
		{ "ModuleRelativePath", "Game/A1Monster.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA1Monster>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AA1Monster_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_A1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA1Monster_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AA1Monster_Statics::ClassParams = {
	&AA1Monster::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA1Monster_Statics::Class_MetaDataParams), Z_Construct_UClass_AA1Monster_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AA1Monster()
{
	if (!Z_Registration_Info_UClass_AA1Monster.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AA1Monster.OuterSingleton, Z_Construct_UClass_AA1Monster_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AA1Monster.OuterSingleton;
}
template<> A1_API UClass* StaticClass<AA1Monster>()
{
	return AA1Monster::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AA1Monster);
// End Class AA1Monster

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Monster_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AA1Monster, AA1Monster::StaticClass, TEXT("AA1Monster"), &Z_Registration_Info_UClass_AA1Monster, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AA1Monster), 2516823693U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Monster_h_167922334(TEXT("/Script/A1"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Monster_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Monster_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
