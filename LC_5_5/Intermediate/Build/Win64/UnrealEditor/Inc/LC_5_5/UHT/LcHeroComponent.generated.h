// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/LcHeroComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LC_5_5_LcHeroComponent_generated_h
#error "LcHeroComponent.generated.h already included, missing '#pragma once' in LcHeroComponent.h"
#endif
#define LC_5_5_LcHeroComponent_generated_h

#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcHeroComponent(); \
	friend struct Z_Construct_UClass_ULcHeroComponent_Statics; \
public: \
	DECLARE_CLASS(ULcHeroComponent, UPawnComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LC_5_5"), NO_API) \
	DECLARE_SERIALIZER(ULcHeroComponent) \
	virtual UObject* _getUObject() const override { return const_cast<ULcHeroComponent*>(this); }


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULcHeroComponent(ULcHeroComponent&&); \
	ULcHeroComponent(const ULcHeroComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcHeroComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcHeroComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcHeroComponent) \
	NO_API virtual ~ULcHeroComponent();


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_14_PROLOG
#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LC_5_5_API UClass* StaticClass<class ULcHeroComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
