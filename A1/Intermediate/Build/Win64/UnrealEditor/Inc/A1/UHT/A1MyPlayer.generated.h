// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/A1MyPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef A1_A1MyPlayer_generated_h
#error "A1MyPlayer.generated.h already included, missing '#pragma once' in A1MyPlayer.h"
#endif
#define A1_A1MyPlayer_generated_h

#define FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAA1MyPlayer(); \
	friend struct Z_Construct_UClass_AA1MyPlayer_Statics; \
public: \
	DECLARE_CLASS(AA1MyPlayer, AA1Player, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1"), NO_API) \
	DECLARE_SERIALIZER(AA1MyPlayer)


#define FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AA1MyPlayer(AA1MyPlayer&&); \
	AA1MyPlayer(const AA1MyPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AA1MyPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AA1MyPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AA1MyPlayer) \
	NO_API virtual ~AA1MyPlayer();


#define FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_13_PROLOG
#define FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_16_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> A1_API UClass* StaticClass<class AA1MyPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_A1_Source_A1_Game_A1MyPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
