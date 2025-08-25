// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Player/LcPlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcPlayerState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerState();
LC_5_5_API UClass* Z_Construct_UClass_ALcPlayerState_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcPlayerState
void ALcPlayerState::StaticRegisterNativesALcPlayerState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcPlayerState);
UClass* Z_Construct_UClass_ALcPlayerState_NoRegister()
{
	return ALcPlayerState::StaticClass();
}
struct Z_Construct_UClass_ALcPlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Player/LcPlayerState.h" },
		{ "ModuleRelativePath", "Player/LcPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcPlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALcPlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcPlayerState_Statics::ClassParams = {
	&ALcPlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcPlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcPlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcPlayerState()
{
	if (!Z_Registration_Info_UClass_ALcPlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcPlayerState.OuterSingleton, Z_Construct_UClass_ALcPlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcPlayerState.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcPlayerState>()
{
	return ALcPlayerState::StaticClass();
}
ALcPlayerState::ALcPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcPlayerState);
ALcPlayerState::~ALcPlayerState() {}
// End Class ALcPlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcPlayerState, ALcPlayerState::StaticClass, TEXT("ALcPlayerState"), &Z_Registration_Info_UClass_ALcPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcPlayerState), 1956057987U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerState_h_2831198908(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Player_LcPlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
