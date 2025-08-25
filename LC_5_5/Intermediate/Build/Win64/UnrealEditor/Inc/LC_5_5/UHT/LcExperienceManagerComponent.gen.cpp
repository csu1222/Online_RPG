// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/GameModes/LcExperienceManagerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcExperienceManagerComponent() {}

// Begin Cross Module References
LC_5_5_API UClass* Z_Construct_UClass_ULcExperienceDefinition_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcExperienceManagerComponent();
LC_5_5_API UClass* Z_Construct_UClass_ULcExperienceManagerComponent_NoRegister();
MODULARGAMEPLAY_API UClass* Z_Construct_UClass_UGameStateComponent();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcExperienceManagerComponent
void ULcExperienceManagerComponent::StaticRegisterNativesULcExperienceManagerComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcExperienceManagerComponent);
UClass* Z_Construct_UClass_ULcExperienceManagerComponent_NoRegister()
{
	return ULcExperienceManagerComponent::StaticClass();
}
struct Z_Construct_UClass_ULcExperienceManagerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * HakExperienceManagerComponent\n * - \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd7\xb4\xef\xbf\xbd\xef\xbf\xbd, \xef\xbf\xbd\xd8\xb4\xef\xbf\xbd component\xef\xbf\xbd\xef\xbf\xbd game state\xef\xbf\xbd\xef\xbf\xbd owner\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe9\xbc\xad, experience\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd component\xef\xbf\xbd\xcc\xb4\xef\xbf\xbd\n * - \xef\xbf\xbd\xd3\xb8\xef\xbf\xbd \xef\xbf\xbd\xc6\xb4\xcf\xb6\xef\xbf\xbd, manager\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xdc\xbe\xee\xb0\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd4\xb5\xc7\xbe\xef\xbf\xbd \xef\xbf\xbd\xd6\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd, experience \xef\xbf\xbd\xce\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xb4\xef\xbf\xbd\n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "GameModes/LcExperienceManagerComponent.h" },
		{ "ModuleRelativePath", "GameModes/LcExperienceManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HakExperienceManagerComponent\n- \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd7\xb4\xef\xbf\xbd\xef\xbf\xbd, \xef\xbf\xbd\xd8\xb4\xef\xbf\xbd component\xef\xbf\xbd\xef\xbf\xbd game state\xef\xbf\xbd\xef\xbf\xbd owner\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe9\xbc\xad, experience\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd component\xef\xbf\xbd\xcc\xb4\xef\xbf\xbd\n- \xef\xbf\xbd\xd3\xb8\xef\xbf\xbd \xef\xbf\xbd\xc6\xb4\xcf\xb6\xef\xbf\xbd, manager\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xdc\xbe\xee\xb0\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd4\xb5\xc7\xbe\xef\xbf\xbd \xef\xbf\xbd\xd6\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd, experience \xef\xbf\xbd\xce\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xb4\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentExperience_MetaData[] = {
		{ "ModuleRelativePath", "GameModes/LcExperienceManagerComponent.h" },
		{ "NativeConstTemplateArg", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentExperience;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcExperienceManagerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULcExperienceManagerComponent_Statics::NewProp_CurrentExperience = { "CurrentExperience", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcExperienceManagerComponent, CurrentExperience), Z_Construct_UClass_ULcExperienceDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentExperience_MetaData), NewProp_CurrentExperience_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcExperienceManagerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcExperienceManagerComponent_Statics::NewProp_CurrentExperience,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcExperienceManagerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcExperienceManagerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameStateComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcExperienceManagerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcExperienceManagerComponent_Statics::ClassParams = {
	&ULcExperienceManagerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcExperienceManagerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcExperienceManagerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcExperienceManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcExperienceManagerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcExperienceManagerComponent()
{
	if (!Z_Registration_Info_UClass_ULcExperienceManagerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcExperienceManagerComponent.OuterSingleton, Z_Construct_UClass_ULcExperienceManagerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcExperienceManagerComponent.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcExperienceManagerComponent>()
{
	return ULcExperienceManagerComponent::StaticClass();
}
ULcExperienceManagerComponent::ULcExperienceManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcExperienceManagerComponent);
ULcExperienceManagerComponent::~ULcExperienceManagerComponent() {}
// End Class ULcExperienceManagerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcExperienceManagerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcExperienceManagerComponent, ULcExperienceManagerComponent::StaticClass, TEXT("ULcExperienceManagerComponent"), &Z_Registration_Info_UClass_ULcExperienceManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcExperienceManagerComponent), 1836630243U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcExperienceManagerComponent_h_3013764159(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcExperienceManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcExperienceManagerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
