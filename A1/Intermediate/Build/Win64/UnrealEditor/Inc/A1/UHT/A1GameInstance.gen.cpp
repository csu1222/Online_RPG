// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1/A1GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1GameInstance() {}

// Begin Cross Module References
A1_API UClass* Z_Construct_UClass_AA1Monster_NoRegister();
A1_API UClass* Z_Construct_UClass_AA1Player_NoRegister();
A1_API UClass* Z_Construct_UClass_UA1GameInstance();
A1_API UClass* Z_Construct_UClass_UA1GameInstance_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
UPackage* Z_Construct_UPackage__Script_A1();
// End Cross Module References

// Begin Class UA1GameInstance Function ConnectToServer
struct Z_Construct_UFunction_UA1GameInstance_ConnectToServer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UA1GameInstance_ConnectToServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UA1GameInstance, nullptr, "ConnectToServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UA1GameInstance_ConnectToServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UA1GameInstance_ConnectToServer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UA1GameInstance_ConnectToServer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UA1GameInstance_ConnectToServer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UA1GameInstance::execConnectToServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectToServer();
	P_NATIVE_END;
}
// End Class UA1GameInstance Function ConnectToServer

// Begin Class UA1GameInstance Function DisconnectFromGameServer
struct Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UA1GameInstance, nullptr, "DisconnectFromGameServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UA1GameInstance::execDisconnectFromGameServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DisconnectFromGameServer();
	P_NATIVE_END;
}
// End Class UA1GameInstance Function DisconnectFromGameServer

// Begin Class UA1GameInstance Function HandleRecvPackets
struct Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UA1GameInstance, nullptr, "HandleRecvPackets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UA1GameInstance::execHandleRecvPackets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRecvPackets();
	P_NATIVE_END;
}
// End Class UA1GameInstance Function HandleRecvPackets

// Begin Class UA1GameInstance
void UA1GameInstance::StaticRegisterNativesUA1GameInstance()
{
	UClass* Class = UA1GameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConnectToServer", &UA1GameInstance::execConnectToServer },
		{ "DisconnectFromGameServer", &UA1GameInstance::execDisconnectFromGameServer },
		{ "HandleRecvPackets", &UA1GameInstance::execHandleRecvPackets },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UA1GameInstance);
UClass* Z_Construct_UClass_UA1GameInstance_NoRegister()
{
	return UA1GameInstance::StaticClass();
}
struct Z_Construct_UClass_UA1GameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "A1GameInstance.h" },
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherPlayerClass_MetaData[] = {
		{ "Category", "A1GameInstance" },
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MonsterClass_MetaData[] = {
		{ "Category", "A1GameInstance" },
		{ "ModuleRelativePath", "A1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_OtherPlayerClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MonsterClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UA1GameInstance_ConnectToServer, "ConnectToServer" }, // 2159237663
		{ &Z_Construct_UFunction_UA1GameInstance_DisconnectFromGameServer, "DisconnectFromGameServer" }, // 544451496
		{ &Z_Construct_UFunction_UA1GameInstance_HandleRecvPackets, "HandleRecvPackets" }, // 2648422713
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UA1GameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UA1GameInstance_Statics::NewProp_OtherPlayerClass = { "OtherPlayerClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UA1GameInstance, OtherPlayerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AA1Player_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherPlayerClass_MetaData), NewProp_OtherPlayerClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UA1GameInstance_Statics::NewProp_MonsterClass = { "MonsterClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UA1GameInstance, MonsterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AA1Monster_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MonsterClass_MetaData), NewProp_MonsterClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UA1GameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UA1GameInstance_Statics::NewProp_OtherPlayerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UA1GameInstance_Statics::NewProp_MonsterClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UA1GameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UA1GameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_A1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UA1GameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UA1GameInstance_Statics::ClassParams = {
	&UA1GameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UA1GameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UA1GameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UA1GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UA1GameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UA1GameInstance()
{
	if (!Z_Registration_Info_UClass_UA1GameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UA1GameInstance.OuterSingleton, Z_Construct_UClass_UA1GameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UA1GameInstance.OuterSingleton;
}
template<> A1_API UClass* StaticClass<UA1GameInstance>()
{
	return UA1GameInstance::StaticClass();
}
UA1GameInstance::UA1GameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UA1GameInstance);
UA1GameInstance::~UA1GameInstance() {}
// End Class UA1GameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UA1GameInstance, UA1GameInstance::StaticClass, TEXT("UA1GameInstance"), &Z_Registration_Info_UClass_UA1GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UA1GameInstance), 980929456U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_350742847(TEXT("/Script/A1"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
