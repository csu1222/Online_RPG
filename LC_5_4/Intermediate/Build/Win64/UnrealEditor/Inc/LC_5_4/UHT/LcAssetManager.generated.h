// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "System/LcAssetManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LC_5_4_LcAssetManager_generated_h
#error "LcAssetManager.generated.h already included, missing '#pragma once' in LcAssetManager.h"
#endif
#define LC_5_4_LcAssetManager_generated_h

#define FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcAssetManager(); \
	friend struct Z_Construct_UClass_ULcAssetManager_Statics; \
public: \
	DECLARE_CLASS(ULcAssetManager, UAssetManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LC_5_4"), NO_API) \
	DECLARE_SERIALIZER(ULcAssetManager)


#define FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULcAssetManager(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULcAssetManager(ULcAssetManager&&); \
	ULcAssetManager(const ULcAssetManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcAssetManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcAssetManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULcAssetManager) \
	NO_API virtual ~ULcAssetManager();


#define FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_12_PROLOG
#define FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_15_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LC_5_4_API UClass* StaticClass<class ULcAssetManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_LC_5_4_Source_LC_5_4_System_LcAssetManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
