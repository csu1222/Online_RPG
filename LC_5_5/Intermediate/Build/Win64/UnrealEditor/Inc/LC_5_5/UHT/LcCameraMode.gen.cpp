// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Camera/LcCameraMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcCameraMode() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraMode_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraModeStack();
LC_5_5_API UClass* Z_Construct_UClass_ULcCameraModeStack_NoRegister();
LC_5_5_API UEnum* Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Enum ELcCameraModeBlendFunction
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELcCameraModeBlendFunction;
static UEnum* ELcCameraModeBlendFunction_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction, (UObject*)Z_Construct_UPackage__Script_LC_5_5(), TEXT("ELcCameraModeBlendFunction"));
	}
	return Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.OuterSingleton;
}
template<> LC_5_5_API UEnum* StaticEnum<ELcCameraModeBlendFunction>()
{
	return ELcCameraModeBlendFunction_StaticEnum();
}
struct Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * [0,1]\xef\xbf\xbd\xef\xbf\xbd BlendFunction\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc2\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\n */" },
#endif
		{ "COUNT.Name", "ELcCameraModeBlendFunction::COUNT" },
		{ "EaseIn.Comment", "/**\n\x09 * EaseIn/Out\xef\xbf\xbd\xef\xbf\xbd exponent \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xb4\xef\xbf\xbd:\n\x09 */" },
		{ "EaseIn.Name", "ELcCameraModeBlendFunction::EaseIn" },
		{ "EaseIn.ToolTip", "EaseIn/Out\xef\xbf\xbd\xef\xbf\xbd exponent \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xb4\xef\xbf\xbd:" },
		{ "EaseInOut.Name", "ELcCameraModeBlendFunction::EaseInOut" },
		{ "EaseOut.Name", "ELcCameraModeBlendFunction::EaseOut" },
		{ "Linear.Name", "ELcCameraModeBlendFunction::Linear" },
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[0,1]\xef\xbf\xbd\xef\xbf\xbd BlendFunction\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc2\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ELcCameraModeBlendFunction::Linear", (int64)ELcCameraModeBlendFunction::Linear },
		{ "ELcCameraModeBlendFunction::EaseIn", (int64)ELcCameraModeBlendFunction::EaseIn },
		{ "ELcCameraModeBlendFunction::EaseOut", (int64)ELcCameraModeBlendFunction::EaseOut },
		{ "ELcCameraModeBlendFunction::EaseInOut", (int64)ELcCameraModeBlendFunction::EaseInOut },
		{ "ELcCameraModeBlendFunction::COUNT", (int64)ELcCameraModeBlendFunction::COUNT },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LC_5_5,
	nullptr,
	"ELcCameraModeBlendFunction",
	"ELcCameraModeBlendFunction",
	Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction()
{
	if (!Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.InnerSingleton, Z_Construct_UEnum_LC_5_5_ELcCameraModeBlendFunction_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ELcCameraModeBlendFunction.InnerSingleton;
}
// End Enum ELcCameraModeBlendFunction

// Begin Class ULcCameraMode
void ULcCameraMode::StaticRegisterNativesULcCameraMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcCameraMode);
UClass* Z_Construct_UClass_ULcCameraMode_NoRegister()
{
	return ULcCameraMode::StaticClass();
}
struct Z_Construct_UClass_ULcCameraMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Camera Blending \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd */" },
#endif
		{ "IncludePath", "Camera/LcCameraMode.h" },
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Blending \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldOfView_MetaData[] = {
		{ "Category", "View" },
		{ "Clampmax", "170.0" },
		{ "ClampMin", "5.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera Mode\xef\xbf\xbd\xef\xbf\xbd FOV */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Mode\xef\xbf\xbd\xef\xbf\xbd FOV" },
#endif
		{ "UIMax", "170" },
		{ "UIMin", "5.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewPitchMin_MetaData[] = {
		{ "Category", "View" },
		{ "Clampmax", "89.9" },
		{ "ClampMin", "-89.9" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** View\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Pitch [Min, Max] */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "View\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Pitch [Min, Max]" },
#endif
		{ "UIMax", "89.9" },
		{ "UIMin", "-89.9" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewPitchMax_MetaData[] = {
		{ "Category", "View" },
		{ "Clampmax", "89.9" },
		{ "ClampMin", "-89.9" },
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
		{ "UIMax", "89.9" },
		{ "UIMin", "-89.9" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlendTime_MetaData[] = {
		{ "Category", "Blending" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xef\xbf\xbd\xf3\xb8\xb6\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Blend\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc7\xb9\xef\xbf\xbd */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xf3\xb8\xb6\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Blend\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc7\xb9\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlendExponent_MetaData[] = {
		{ "Category", "Blending" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* EaseIn/Out\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Exponent\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EaseIn/Out\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Exponent" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FieldOfView;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ViewPitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ViewPitchMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendExponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcCameraMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULcCameraMode_Statics::NewProp_FieldOfView = { "FieldOfView", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode, FieldOfView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldOfView_MetaData), NewProp_FieldOfView_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULcCameraMode_Statics::NewProp_ViewPitchMin = { "ViewPitchMin", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode, ViewPitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewPitchMin_MetaData), NewProp_ViewPitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULcCameraMode_Statics::NewProp_ViewPitchMax = { "ViewPitchMax", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode, ViewPitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewPitchMax_MetaData), NewProp_ViewPitchMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULcCameraMode_Statics::NewProp_BlendTime = { "BlendTime", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode, BlendTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlendTime_MetaData), NewProp_BlendTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULcCameraMode_Statics::NewProp_BlendExponent = { "BlendExponent", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraMode, BlendExponent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlendExponent_MetaData), NewProp_BlendExponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcCameraMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_Statics::NewProp_FieldOfView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_Statics::NewProp_ViewPitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_Statics::NewProp_ViewPitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_Statics::NewProp_BlendTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraMode_Statics::NewProp_BlendExponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcCameraMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcCameraMode_Statics::ClassParams = {
	&ULcCameraMode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcCameraMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcCameraMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcCameraMode()
{
	if (!Z_Registration_Info_UClass_ULcCameraMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcCameraMode.OuterSingleton, Z_Construct_UClass_ULcCameraMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcCameraMode.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcCameraMode>()
{
	return ULcCameraMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcCameraMode);
ULcCameraMode::~ULcCameraMode() {}
// End Class ULcCameraMode

// Begin Class ULcCameraModeStack
void ULcCameraModeStack::StaticRegisterNativesULcCameraModeStack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcCameraModeStack);
UClass* Z_Construct_UClass_ULcCameraModeStack_NoRegister()
{
	return ULcCameraModeStack::StaticClass();
}
struct Z_Construct_UClass_ULcCameraModeStack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Camera Blending\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc3\xbc */" },
#endif
		{ "IncludePath", "Camera/LcCameraMode.h" },
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Blending\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc3\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraModeInstances_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd CameraMode\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd CameraMode\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraModeStack_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera Matrix Blend \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xa5 */" },
#endif
		{ "ModuleRelativePath", "Camera/LcCameraMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Matrix Blend \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xa5" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraModeInstances_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CameraModeInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraModeStack_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CameraModeStack;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcCameraModeStack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeInstances_Inner = { "CameraModeInstances", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULcCameraMode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeInstances = { "CameraModeInstances", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraModeStack, CameraModeInstances), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraModeInstances_MetaData), NewProp_CameraModeInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeStack_Inner = { "CameraModeStack", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULcCameraMode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeStack = { "CameraModeStack", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcCameraModeStack, CameraModeStack), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraModeStack_MetaData), NewProp_CameraModeStack_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcCameraModeStack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeInstances_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeStack_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcCameraModeStack_Statics::NewProp_CameraModeStack,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraModeStack_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcCameraModeStack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraModeStack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcCameraModeStack_Statics::ClassParams = {
	&ULcCameraModeStack::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcCameraModeStack_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraModeStack_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcCameraModeStack_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcCameraModeStack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcCameraModeStack()
{
	if (!Z_Registration_Info_UClass_ULcCameraModeStack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcCameraModeStack.OuterSingleton, Z_Construct_UClass_ULcCameraModeStack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcCameraModeStack.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcCameraModeStack>()
{
	return ULcCameraModeStack::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcCameraModeStack);
ULcCameraModeStack::~ULcCameraModeStack() {}
// End Class ULcCameraModeStack

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ELcCameraModeBlendFunction_StaticEnum, TEXT("ELcCameraModeBlendFunction"), &Z_Registration_Info_UEnum_ELcCameraModeBlendFunction, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3882138945U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcCameraMode, ULcCameraMode::StaticClass, TEXT("ULcCameraMode"), &Z_Registration_Info_UClass_ULcCameraMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcCameraMode), 215646343U) },
		{ Z_Construct_UClass_ULcCameraModeStack, ULcCameraModeStack::StaticClass, TEXT("ULcCameraModeStack"), &Z_Registration_Info_UClass_ULcCameraModeStack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcCameraModeStack), 3471300103U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_3024932628(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Camera_LcCameraMode_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
