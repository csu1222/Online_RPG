// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "A1AIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef A1_A1AIController_generated_h
#error "A1AIController.generated.h already included, missing '#pragma once' in A1AIController.h"
#endif
#define A1_A1AIController_generated_h

#define FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAA1AIController(); \
	friend struct Z_Construct_UClass_AA1AIController_Statics; \
public: \
	DECLARE_CLASS(AA1AIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/A1"), NO_API) \
	DECLARE_SERIALIZER(AA1AIController)


#define FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AA1AIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AA1AIController(AA1AIController&&); \
	AA1AIController(const AA1AIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AA1AIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AA1AIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AA1AIController) \
	NO_API virtual ~AA1AIController();


#define FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_12_PROLOG
#define FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_15_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> A1_API UClass* StaticClass<class AA1AIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_A1_Source_A1_A1AIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
