// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "A1/A1GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA1GameModeBase() {}

// Begin Cross Module References
A1_API UClass* Z_Construct_UClass_AA1GameModeBase();
A1_API UClass* Z_Construct_UClass_AA1GameModeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_A1();
// End Cross Module References

// Begin Class AA1GameModeBase
void AA1GameModeBase::StaticRegisterNativesAA1GameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AA1GameModeBase);
UClass* Z_Construct_UClass_AA1GameModeBase_NoRegister()
{
	return AA1GameModeBase::StaticClass();
}
struct Z_Construct_UClass_AA1GameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "A1GameModeBase.h" },
		{ "ModuleRelativePath", "A1GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA1GameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AA1GameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_A1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA1GameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AA1GameModeBase_Statics::ClassParams = {
	&AA1GameModeBase::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA1GameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AA1GameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AA1GameModeBase()
{
	if (!Z_Registration_Info_UClass_AA1GameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AA1GameModeBase.OuterSingleton, Z_Construct_UClass_AA1GameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AA1GameModeBase.OuterSingleton;
}
template<> A1_API UClass* StaticClass<AA1GameModeBase>()
{
	return AA1GameModeBase::StaticClass();
}
AA1GameModeBase::AA1GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AA1GameModeBase);
AA1GameModeBase::~AA1GameModeBase() {}
// End Class AA1GameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AA1GameModeBase, AA1GameModeBase::StaticClass, TEXT("AA1GameModeBase"), &Z_Registration_Info_UClass_AA1GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AA1GameModeBase), 3910690103U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameModeBase_h_1084937787(TEXT("/Script/A1"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_A1_Source_A1_A1GameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
