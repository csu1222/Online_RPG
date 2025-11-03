// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Input/LcInputComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcInputComponent() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent();
LC_5_5_API UClass* Z_Construct_UClass_ULcInputComponent();
LC_5_5_API UClass* Z_Construct_UClass_ULcInputComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcInputComponent
void ULcInputComponent::StaticRegisterNativesULcInputComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcInputComponent);
UClass* Z_Construct_UClass_ULcInputComponent_NoRegister()
{
	return ULcInputComponent::StaticClass();
}
struct Z_Construct_UClass_ULcInputComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Activation Components|Activation Activation Components|Activation" },
		{ "IncludePath", "Input/LcInputComponent.h" },
		{ "ModuleRelativePath", "Input/LcInputComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcInputComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULcInputComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEnhancedInputComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcInputComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcInputComponent_Statics::ClassParams = {
	&ULcInputComponent::StaticClass,
	"Input",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcInputComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcInputComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcInputComponent()
{
	if (!Z_Registration_Info_UClass_ULcInputComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcInputComponent.OuterSingleton, Z_Construct_UClass_ULcInputComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcInputComponent.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcInputComponent>()
{
	return ULcInputComponent::StaticClass();
}
ULcInputComponent::ULcInputComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcInputComponent);
ULcInputComponent::~ULcInputComponent() {}
// End Class ULcInputComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcInputComponent, ULcInputComponent::StaticClass, TEXT("ULcInputComponent"), &Z_Registration_Info_UClass_ULcInputComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcInputComponent), 1766309317U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputComponent_h_1153283633(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcInputComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
