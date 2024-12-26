// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OnlineRPGGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ONLINERPG_OnlineRPGGameInstance_generated_h
#error "OnlineRPGGameInstance.generated.h already included, missing '#pragma once' in OnlineRPGGameInstance.h"
#endif
#define ONLINERPG_OnlineRPGGameInstance_generated_h

#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_SPARSE_DATA
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleRecvPackets); \
	DECLARE_FUNCTION(execDisconnectFromGameServer); \
	DECLARE_FUNCTION(execConnectToGameServer);


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlineRPGGameInstance(); \
	friend struct Z_Construct_UClass_UOnlineRPGGameInstance_Statics; \
public: \
	DECLARE_CLASS(UOnlineRPGGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/OnlineRPG"), NO_API) \
	DECLARE_SERIALIZER(UOnlineRPGGameInstance)


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlineRPGGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlineRPGGameInstance(UOnlineRPGGameInstance&&); \
	NO_API UOnlineRPGGameInstance(const UOnlineRPGGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlineRPGGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlineRPGGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlineRPGGameInstance) \
	NO_API virtual ~UOnlineRPGGameInstance();


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_13_PROLOG
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_SPARSE_DATA \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINERPG_API UClass* StaticClass<class UOnlineRPGGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_OnlineRPGGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
