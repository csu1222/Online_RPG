// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/GameModes/LcGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcGameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
LC_5_5_API UClass* Z_Construct_UClass_ALcGameModeBase();
LC_5_5_API UClass* Z_Construct_UClass_ALcGameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ALcGameModeBase
void ALcGameModeBase::StaticRegisterNativesALcGameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALcGameModeBase);
UClass* Z_Construct_UClass_ALcGameModeBase_NoRegister()
{
	return ALcGameModeBase::StaticClass();
}
struct Z_Construct_UClass_ALcGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameModes/LcGameModeBase.h" },
		{ "ModuleRelativePath", "GameModes/LcGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALcGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALcGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALcGameModeBase_Statics::ClassParams = {
	&ALcGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALcGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ALcGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALcGameModeBase()
{
	if (!Z_Registration_Info_UClass_ALcGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALcGameModeBase.OuterSingleton, Z_Construct_UClass_ALcGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALcGameModeBase.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ALcGameModeBase>()
{
	return ALcGameModeBase::StaticClass();
}
ALcGameModeBase::ALcGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALcGameModeBase);
ALcGameModeBase::~ALcGameModeBase() {}
// End Class ALcGameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALcGameModeBase, ALcGameModeBase::StaticClass, TEXT("ALcGameModeBase"), &Z_Registration_Info_UClass_ALcGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALcGameModeBase), 4072130255U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameModeBase_h_887360888(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_GameModes_LcGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
