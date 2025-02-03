// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineRPG/Game/OR_Env.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOR_Env() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Env();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Env_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineRPG();
// End Cross Module References
	void AOR_Env::StaticRegisterNativesAOR_Env()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOR_Env);
	UClass* Z_Construct_UClass_AOR_Env_NoRegister()
	{
		return AOR_Env::StaticClass();
	}
	struct Z_Construct_UClass_AOR_Env_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOR_Env_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineRPG,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_Env_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_Env_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Game/OR_Env.h" },
		{ "ModuleRelativePath", "Game/OR_Env.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOR_Env_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOR_Env>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOR_Env_Statics::ClassParams = {
		&AOR_Env::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_Env_Statics::Class_MetaDataParams), Z_Construct_UClass_AOR_Env_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AOR_Env()
	{
		if (!Z_Registration_Info_UClass_AOR_Env.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOR_Env.OuterSingleton, Z_Construct_UClass_AOR_Env_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOR_Env.OuterSingleton;
	}
	template<> ONLINERPG_API UClass* StaticClass<AOR_Env>()
	{
		return AOR_Env::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOR_Env);
	AOR_Env::~AOR_Env() {}
	struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Env_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Env_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOR_Env, AOR_Env::StaticClass, TEXT("AOR_Env"), &Z_Registration_Info_UClass_AOR_Env, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOR_Env), 2078614716U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Env_h_4254236212(TEXT("/Script/OnlineRPG"),
		Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Env_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Env_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
