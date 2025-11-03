// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Character/LcHeroComponent.h"
#include "LC_5_5/Input/LcMappableConfigPair.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcHeroComponent() {}

// Begin Cross Module References
LC_5_5_API UClass* Z_Construct_UClass_ULcHeroComponent();
LC_5_5_API UClass* Z_Construct_UClass_ULcHeroComponent_NoRegister();
LC_5_5_API UScriptStruct* Z_Construct_UScriptStruct_FLcMappableConfigPair();
MODULARGAMEPLAY_API UClass* Z_Construct_UClass_UGameFrameworkInitStateInterface_NoRegister();
MODULARGAMEPLAY_API UClass* Z_Construct_UClass_UPawnComponent();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcHeroComponent
void ULcHeroComponent::StaticRegisterNativesULcHeroComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcHeroComponent);
UClass* Z_Construct_UClass_ULcHeroComponent_NoRegister()
{
	return ULcHeroComponent::StaticClass();
}
struct Z_Construct_UClass_ULcHeroComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Character/LcHeroComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Character/LcHeroComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInputConfigs_MetaData[] = {
		{ "Category", "LcHeroComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* member variables\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Character/LcHeroComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "member variables" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultInputConfigs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultInputConfigs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcHeroComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULcHeroComponent_Statics::NewProp_DefaultInputConfigs_Inner = { "DefaultInputConfigs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLcMappableConfigPair, METADATA_PARAMS(0, nullptr) }; // 3802773227
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULcHeroComponent_Statics::NewProp_DefaultInputConfigs = { "DefaultInputConfigs", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcHeroComponent, DefaultInputConfigs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultInputConfigs_MetaData), NewProp_DefaultInputConfigs_MetaData) }; // 3802773227
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcHeroComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcHeroComponent_Statics::NewProp_DefaultInputConfigs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcHeroComponent_Statics::NewProp_DefaultInputConfigs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcHeroComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcHeroComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPawnComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcHeroComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ULcHeroComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UGameFrameworkInitStateInterface_NoRegister, (int32)VTABLE_OFFSET(ULcHeroComponent, IGameFrameworkInitStateInterface), false },  // 363983679
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcHeroComponent_Statics::ClassParams = {
	&ULcHeroComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcHeroComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcHeroComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcHeroComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcHeroComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcHeroComponent()
{
	if (!Z_Registration_Info_UClass_ULcHeroComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcHeroComponent.OuterSingleton, Z_Construct_UClass_ULcHeroComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcHeroComponent.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcHeroComponent>()
{
	return ULcHeroComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcHeroComponent);
ULcHeroComponent::~ULcHeroComponent() {}
// End Class ULcHeroComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcHeroComponent, ULcHeroComponent::StaticClass, TEXT("ULcHeroComponent"), &Z_Registration_Info_UClass_ULcHeroComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcHeroComponent), 3858975546U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_2777728430(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcHeroComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
