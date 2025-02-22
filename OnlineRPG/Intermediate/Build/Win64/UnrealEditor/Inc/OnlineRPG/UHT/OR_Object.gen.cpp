// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineRPG/Game/OR_Object.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOR_Object() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ONLINERPG_API UClass* Z_Construct_UClass_UOR_Object();
	ONLINERPG_API UClass* Z_Construct_UClass_UOR_Object_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineRPG();
// End Cross Module References
	void UOR_Object::StaticRegisterNativesUOR_Object()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOR_Object);
	UClass* Z_Construct_UClass_UOR_Object_NoRegister()
	{
		return UOR_Object::StaticClass();
	}
	struct Z_Construct_UClass_UOR_Object_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOR_Object_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineRPG,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOR_Object_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOR_Object_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Game/OR_Object.h" },
		{ "ModuleRelativePath", "Game/OR_Object.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOR_Object_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOR_Object>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOR_Object_Statics::ClassParams = {
		&UOR_Object::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOR_Object_Statics::Class_MetaDataParams), Z_Construct_UClass_UOR_Object_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOR_Object()
	{
		if (!Z_Registration_Info_UClass_UOR_Object.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOR_Object.OuterSingleton, Z_Construct_UClass_UOR_Object_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOR_Object.OuterSingleton;
	}
	template<> ONLINERPG_API UClass* StaticClass<UOR_Object>()
	{
		return UOR_Object::StaticClass();
	}
	UOR_Object::UOR_Object(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOR_Object);
	UOR_Object::~UOR_Object() {}
	struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Object_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Object_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOR_Object, UOR_Object::StaticClass, TEXT("UOR_Object"), &Z_Registration_Info_UClass_UOR_Object, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOR_Object), 2464138580U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Object_h_1040013250(TEXT("/Script/OnlineRPG"),
		Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Object_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_Object_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
