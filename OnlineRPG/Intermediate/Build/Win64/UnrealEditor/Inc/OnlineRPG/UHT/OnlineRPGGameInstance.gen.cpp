// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineRPG/OnlineRPGGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlineRPGGameInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	ONLINERPG_API UClass* Z_Construct_UClass_UOnlineRPGGameInstance();
	ONLINERPG_API UClass* Z_Construct_UClass_UOnlineRPGGameInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineRPG();
// End Cross Module References
	DEFINE_FUNCTION(UOnlineRPGGameInstance::execHandleRecvPackets)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleRecvPackets();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlineRPGGameInstance::execDisconnectFromGameServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisconnectFromGameServer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlineRPGGameInstance::execConnectToGameServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ConnectToGameServer();
		P_NATIVE_END;
	}
	void UOnlineRPGGameInstance::StaticRegisterNativesUOnlineRPGGameInstance()
	{
		UClass* Class = UOnlineRPGGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConnectToGameServer", &UOnlineRPGGameInstance::execConnectToGameServer },
			{ "DisconnectFromGameServer", &UOnlineRPGGameInstance::execDisconnectFromGameServer },
			{ "HandleRecvPackets", &UOnlineRPGGameInstance::execHandleRecvPackets },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineRPGGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlineRPGGameInstance, nullptr, "ConnectToGameServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineRPGGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlineRPGGameInstance, nullptr, "DisconnectFromGameServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineRPGGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlineRPGGameInstance, nullptr, "HandleRecvPackets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlineRPGGameInstance);
	UClass* Z_Construct_UClass_UOnlineRPGGameInstance_NoRegister()
	{
		return UOnlineRPGGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UOnlineRPGGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlineRPGGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineRPG,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineRPGGameInstance_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlineRPGGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlineRPGGameInstance_ConnectToGameServer, "ConnectToGameServer" }, // 694281626
		{ &Z_Construct_UFunction_UOnlineRPGGameInstance_DisconnectFromGameServer, "DisconnectFromGameServer" }, // 2819588702
		{ &Z_Construct_UFunction_UOnlineRPGGameInstance_HandleRecvPackets, "HandleRecvPackets" }, // 3148872691
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineRPGGameInstance_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineRPGGameInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "OnlineRPGGameInstance.h" },
		{ "ModuleRelativePath", "OnlineRPGGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlineRPGGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlineRPGGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlineRPGGameInstance_Statics::ClassParams = {
		&UOnlineRPGGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineRPGGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlineRPGGameInstance_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlineRPGGameInstance()
	{
		if (!Z_Registration_Info_UClass_UOnlineRPGGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlineRPGGameInstance.OuterSingleton, Z_Construct_UClass_UOnlineRPGGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlineRPGGameInstance.OuterSingleton;
	}
	template<> ONLINERPG_API UClass* StaticClass<UOnlineRPGGameInstance>()
	{
		return UOnlineRPGGameInstance::StaticClass();
	}
	UOnlineRPGGameInstance::UOnlineRPGGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlineRPGGameInstance);
	UOnlineRPGGameInstance::~UOnlineRPGGameInstance() {}
	struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlineRPGGameInstance, UOnlineRPGGameInstance::StaticClass, TEXT("UOnlineRPGGameInstance"), &Z_Registration_Info_UClass_UOnlineRPGGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlineRPGGameInstance), 3441565994U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_3120458334(TEXT("/Script/OnlineRPG"),
		Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
