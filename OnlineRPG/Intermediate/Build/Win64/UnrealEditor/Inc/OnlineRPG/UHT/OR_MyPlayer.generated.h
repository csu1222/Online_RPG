// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/OR_MyPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AOR_Env_ItrAble;
struct FHitResult;
#ifdef ONLINERPG_OR_MyPlayer_generated_h
#error "OR_MyPlayer.generated.h already included, missing '#pragma once' in OR_MyPlayer.h"
#endif
#define ONLINERPG_OR_MyPlayer_generated_h

#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_SPARSE_DATA
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCanInteracte); \
	DECLARE_FUNCTION(execGetDistanceBetweenMeAndTarget); \
	DECLARE_FUNCTION(execCheckAimedObject);


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_ACCESSORS
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOR_MyPlayer(); \
	friend struct Z_Construct_UClass_AOR_MyPlayer_Statics; \
public: \
	DECLARE_CLASS(AOR_MyPlayer, AOR_Player, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineRPG"), NO_API) \
	DECLARE_SERIALIZER(AOR_MyPlayer)


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOR_MyPlayer(AOR_MyPlayer&&); \
	NO_API AOR_MyPlayer(const AOR_MyPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOR_MyPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOR_MyPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOR_MyPlayer) \
	NO_API virtual ~AOR_MyPlayer();


#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_14_PROLOG
#define FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_SPARSE_DATA \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_ACCESSORS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINERPG_API UClass* StaticClass<class AOR_MyPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_OnlineRPG_Source_OnlineRPG_Game_OR_MyPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
