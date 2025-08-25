// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/GameModes/LcGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcGameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
LC_5_5_API UClass* Z_Construct_UClass_ALcGameState();
LC_5_5_API UClass* Z_Construct_UClass_ALcGameState_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcExperienceManagerComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcGameState
void ALcGameState::StaticRegisterNativesALcGameState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcGameState);
UClass* Z_Construct_UClass_ALcGameState_NoRegister()
{
	return ALcGameState::StaticClass();
}
struct Z_Construct_UClass_ALcGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameModes/LcGameState.h" },
		{ "ModuleRelativePath", "GameModes/LcGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceManagerComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameModes/LcGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceManagerComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALcGameState_Statics::NewProp_ExperienceManagerComponent = { "ExperienceManagerComponent", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALcGameState, ExperienceManagerComponent), Z_Construct_UClass_ULcExperienceManagerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceManagerComponent_MetaData), NewProp_ExperienceManagerComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALcGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALcGameState_Statics::NewProp_ExperienceManagerComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALcGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameStateBase,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcGameState_Statics::ClassParams = {
	&ALcGameState::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ALcGameState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcGameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcGameState()
{
	if (!Z_Registration_Info_UClass_ALcGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcGameState.OuterSingleton, Z_Construct_UClass_ALcGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcGameState.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcGameState>()
{
	return ALcGameState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcGameState);
ALcGameState::~ALcGameState() {}
// End Class ALcGameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcGameState, ALcGameState::StaticClass, TEXT("ALcGameState"), &Z_Registration_Info_UClass_ALcGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcGameState), 1651828598U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameState_h_3779484771(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
