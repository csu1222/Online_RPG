// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineRPG/Game/OR_MyPlayer.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOR_MyPlayer() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Env_ItrAble_NoRegister();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_MyPlayer();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_MyPlayer_NoRegister();
	ONLINERPG_API UClass* Z_Construct_UClass_AOR_Player();
	UPackage* Z_Construct_UPackage__Script_OnlineRPG();
// End Cross Module References
	DEFINE_FUNCTION(AOR_MyPlayer::execCanInteracte)
	{
		P_GET_STRUCT(FHitResult,Z_Param_HitResult);
		P_GET_OBJECT(AOR_Env_ItrAble,Z_Param_Interactable);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanInteracte(Z_Param_HitResult,Z_Param_Interactable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOR_MyPlayer::execGetDistanceBetweenMeAndTarget)
	{
		P_GET_STRUCT(FHitResult,Z_Param_HitResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetDistanceBetweenMeAndTarget(Z_Param_HitResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOR_MyPlayer::execCheckAimedObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CheckAimedObject();
		P_NATIVE_END;
	}
	void AOR_MyPlayer::StaticRegisterNativesAOR_MyPlayer()
	{
		UClass* Class = AOR_MyPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanInteracte", &AOR_MyPlayer::execCanInteracte },
			{ "CheckAimedObject", &AOR_MyPlayer::execCheckAimedObject },
			{ "GetDistanceBetweenMeAndTarget", &AOR_MyPlayer::execGetDistanceBetweenMeAndTarget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics
	{
		struct OR_MyPlayer_eventCanInteracte_Parms
		{
			FHitResult HitResult;
			AOR_Env_ItrAble* Interactable;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactable;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_HitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OR_MyPlayer_eventCanInteracte_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_HitResult_MetaData), Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_HitResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_Interactable = { "Interactable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OR_MyPlayer_eventCanInteracte_Parms, Interactable), Z_Construct_UClass_AOR_Env_ItrAble_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OR_MyPlayer_eventCanInteracte_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OR_MyPlayer_eventCanInteracte_Parms), &Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_HitResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_Interactable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOR_MyPlayer, nullptr, "CanInteracte", nullptr, nullptr, Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::OR_MyPlayer_eventCanInteracte_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::OR_MyPlayer_eventCanInteracte_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOR_MyPlayer_CanInteracte()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOR_MyPlayer_CanInteracte_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Interacte Action\n" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interacte Action" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOR_MyPlayer, nullptr, "CheckAimedObject", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics
	{
		struct OR_MyPlayer_eventGetDistanceBetweenMeAndTarget_Parms
		{
			FHitResult HitResult;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_HitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OR_MyPlayer_eventGetDistanceBetweenMeAndTarget_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_HitResult_MetaData), Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_HitResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OR_MyPlayer_eventGetDistanceBetweenMeAndTarget_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_HitResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOR_MyPlayer, nullptr, "GetDistanceBetweenMeAndTarget", nullptr, nullptr, Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::OR_MyPlayer_eventGetDistanceBetweenMeAndTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::OR_MyPlayer_eventGetDistanceBetweenMeAndTarget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOR_MyPlayer);
	UClass* Z_Construct_UClass_AOR_MyPlayer_NoRegister()
	{
		return AOR_MyPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AOR_MyPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InteracteAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InteracteAction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOR_MyPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AOR_Player,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineRPG,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AOR_MyPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOR_MyPlayer_CanInteracte, "CanInteracte" }, // 3179705694
		{ &Z_Construct_UFunction_AOR_MyPlayer_CheckAimedObject, "CheckAimedObject" }, // 3832804990
		{ &Z_Construct_UFunction_AOR_MyPlayer_GetDistanceBetweenMeAndTarget, "GetDistanceBetweenMeAndTarget" }, // 1459963350
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/OR_MyPlayer.h" },
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_InteracteAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Interacte Input Action */" },
#endif
		{ "ModuleRelativePath", "Game/OR_MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interacte Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_InteracteAction = { "InteracteAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOR_MyPlayer, InteracteAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_InteracteAction_MetaData), Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_InteracteAction_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOR_MyPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOR_MyPlayer_Statics::NewProp_InteracteAction,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOR_MyPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOR_MyPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOR_MyPlayer_Statics::ClassParams = {
		&AOR_MyPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AOR_MyPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AOR_MyPlayer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOR_MyPlayer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AOR_MyPlayer()
	{
		if (!Z_Registration_Info_UClass_AOR_MyPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOR_MyPlayer.OuterSingleton, Z_Construct_UClass_AOR_MyPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOR_MyPlayer.OuterSingleton;
	}
	template<> ONLINERPG_API UClass* StaticClass<AOR_MyPlayer>()
	{
		return AOR_MyPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOR_MyPlayer);
	AOR_MyPlayer::~AOR_MyPlayer() {}
	struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOR_MyPlayer, AOR_MyPlayer::StaticClass, TEXT("AOR_MyPlayer"), &Z_Registration_Info_UClass_AOR_MyPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOR_MyPlayer), 2301783515U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_1670930552(TEXT("/Script/OnlineRPG"),
		Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
