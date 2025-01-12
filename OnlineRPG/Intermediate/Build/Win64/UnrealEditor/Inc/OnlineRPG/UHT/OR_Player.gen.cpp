// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineRPG/Game/OR_Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOR_Player() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Player();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Player_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineRPG();
// End Cross Module References
	void AOR_Player::StaticRegisterNativesAOR_Player()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOR_Player);
	UClass* Z_Construct_UClass_AOR_Player_NoRegister()
	{
		return AOR_Player::StaticClass();
	}
	struct Z_Construct_UClass_AOR_Player_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOR_Player_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineRPG,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_Player_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_Player_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/OR_Player.h" },
		{ "ModuleRelativePath", "Game/OR_Player.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOR_Player_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOR_Player>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOR_Player_Statics::ClassParams = {
		&AOR_Player::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_Player_Statics::Class_MetaDataParams), Z_Construct_UClass_AOR_Player_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AOR_Player()
	{
		if (!Z_Registration_Info_UClass_AOR_Player.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOR_Player.OuterSingleton, Z_Construct_UClass_AOR_Player_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOR_Player.OuterSingleton;
	}
	template<> ONLINERPG_API UClass* StaticClass<AOR_Player>()
	{
		return AOR_Player::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOR_Player);
	struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Player_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Player_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOR_Player, AOR_Player::StaticClass, TEXT("AOR_Player"), &Z_Registration_Info_UClass_AOR_Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOR_Player), 2529838427U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Player_h_1851091123(TEXT("/Script/OnlineRPG"),
		Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Player_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
