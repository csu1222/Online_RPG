// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1/Game/A1Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1Player() {}

// Begin Cross Module References
A1_API UClass* Z_Construct_UClass_AA1Player();
A1_API UClass* Z_Construct_UClass_AA1Player_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_A1();
// End Cross Module References

// Begin Class AA1Player
void AA1Player::StaticRegisterNativesAA1Player()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AA1Player);
UClass* Z_Construct_UClass_AA1Player_NoRegister()
{
	return AA1Player::StaticClass();
}
struct Z_Construct_UClass_AA1Player_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/A1Player.h" },
		{ "ModuleRelativePath", "Game/A1Player.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA1Player>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AA1Player_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_A1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA1Player_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AA1Player_Statics::ClassParams = {
	&AA1Player::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA1Player_Statics::Class_MetaDataParams), Z_Construct_UClass_AA1Player_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AA1Player()
{
	if (!Z_Registration_Info_UClass_AA1Player.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AA1Player.OuterSingleton, Z_Construct_UClass_AA1Player_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AA1Player.OuterSingleton;
}
template<> A1_API UClass* StaticClass<AA1Player>()
{
	return AA1Player::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AA1Player);
// End Class AA1Player

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Player_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AA1Player, AA1Player::StaticClass, TEXT("AA1Player"), &Z_Registration_Info_UClass_AA1Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AA1Player), 3285255212U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Player_h_591757434(TEXT("/Script/A1"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1Player_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
