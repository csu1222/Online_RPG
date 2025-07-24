// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "A1GameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef A1_A1GameInstance_generated_h
#error "A1GameInstance.generated.h already included, missing '#pragma once' in A1GameInstance.h"
#endif
#define A1_A1GameInstance_generated_h

#define FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleRecvPackets); \
	DECLARE_FUNCTION(execDisconnectFromGameServer); \
	DECLARE_FUNCTION(execConnectToServer);


#define FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUA1GameInstance(); \
	friend struct Z_Construct_UClass_UA1GameInstance_Statics; \
public: \
	DECLARE_CLASS(UA1GameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/A1"), NO_API) \
	DECLARE_SERIALIZER(UA1GameInstance)


#define FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UA1GameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UA1GameInstance(UA1GameInstance&&); \
	UA1GameInstance(const UA1GameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UA1GameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UA1GameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UA1GameInstance) \
	NO_API virtual ~UA1GameInstance();


#define FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_14_PROLOG
#define FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> A1_API UClass* StaticClass<class UA1GameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_A1_Source_A1_A1GameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
