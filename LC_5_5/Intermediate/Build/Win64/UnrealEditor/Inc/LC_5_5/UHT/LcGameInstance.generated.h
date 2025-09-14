// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "System/LcGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LC_5_5_LcGameInstance_generated_h
#error "LcGameInstance.generated.h already included, missing '#pragma once' in LcGameInstance.h"
#endif
#define LC_5_5_LcGameInstance_generated_h

#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcGameInstance(); \
	friend struct Z_Construct_UClass_ULcGameInstance_Statics; \
public: \
	DECLARE_CLASS(ULcGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LC_5_5"), NO_API) \
	DECLARE_SERIALIZER(ULcGameInstance)


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULcGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULcGameInstance(ULcGameInstance&&); \
	ULcGameInstance(const ULcGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcGameInstance) \
	NO_API virtual ~ULcGameInstance();


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_12_PROLOG
#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LC_5_5_API UClass* StaticClass<class ULcGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
