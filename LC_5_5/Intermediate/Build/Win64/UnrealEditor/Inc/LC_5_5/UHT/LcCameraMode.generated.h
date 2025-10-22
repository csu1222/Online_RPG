// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Camera/LcCameraMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LC_5_5_LcCameraMode_generated_h
#error "LcCameraMode.generated.h already included, missing '#pragma once' in LcCameraMode.h"
#endif
#define LC_5_5_LcCameraMode_generated_h

#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcCameraMode(); \
	friend struct Z_Construct_UClass_ULcCameraMode_Statics; \
public: \
	DECLARE_CLASS(ULcCameraMode, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LC_5_5"), NO_API) \
	DECLARE_SERIALIZER(ULcCameraMode)


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_50_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULcCameraMode(ULcCameraMode&&); \
	ULcCameraMode(const ULcCameraMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcCameraMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcCameraMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcCameraMode) \
	NO_API virtual ~ULcCameraMode();


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_47_PROLOG
#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_50_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LC_5_5_API UClass* StaticClass<class ULcCameraMode>();

#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_112_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcCameraModeStack(); \
	friend struct Z_Construct_UClass_ULcCameraModeStack_Statics; \
public: \
	DECLARE_CLASS(ULcCameraModeStack, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LC_5_5"), NO_API) \
	DECLARE_SERIALIZER(ULcCameraModeStack)


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_112_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULcCameraModeStack(ULcCameraModeStack&&); \
	ULcCameraModeStack(const ULcCameraModeStack&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcCameraModeStack); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcCameraModeStack); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcCameraModeStack) \
	NO_API virtual ~ULcCameraModeStack();


#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_109_PROLOG
#define FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_112_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_112_INCLASS_NO_PURE_DECLS \
	FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_112_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LC_5_5_API UClass* StaticClass<class ULcCameraModeStack>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h


#define FOREACH_ENUM_ELCCAMERAMODEBLENDFUNCTION(op) \
	op(ELcCameraModeBlendFunction::Linear) \
	op(ELcCameraModeBlendFunction::EaseIn) \
	op(ELcCameraModeBlendFunction::EaseOut) \
	op(ELcCameraModeBlendFunction::EaseInOut) \
	op(ELcCameraModeBlendFunction::COUNT) 

enum class ELcCameraModeBlendFunction : uint8;
template<> struct TIsUEnumClass<ELcCameraModeBlendFunction> { enum { Value = true }; };
template<> LC_5_5_API UEnum* StaticEnum<ELcCameraModeBlendFunction>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
