// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/System/LcGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
LC_5_5_API UClass* Z_Construct_UClass_ULcGameInstance();
LC_5_5_API UClass* Z_Construct_UClass_ULcGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcGameInstance
void ULcGameInstance::StaticRegisterNativesULcGameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcGameInstance);
UClass* Z_Construct_UClass_ULcGameInstance_NoRegister()
{
	return ULcGameInstance::StaticClass();
}
struct Z_Construct_UClass_ULcGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/LcGameInstance.h" },
		{ "ModuleRelativePath", "System/LcGameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULcGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcGameInstance_Statics::ClassParams = {
	&ULcGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcGameInstance()
{
	if (!Z_Registration_Info_UClass_ULcGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcGameInstance.OuterSingleton, Z_Construct_UClass_ULcGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcGameInstance.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcGameInstance>()
{
	return ULcGameInstance::StaticClass();
}
ULcGameInstance::ULcGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcGameInstance);
ULcGameInstance::~ULcGameInstance() {}
// End Class ULcGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcGameInstance, ULcGameInstance::StaticClass, TEXT("ULcGameInstance"), &Z_Registration_Info_UClass_ULcGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcGameInstance), 2013742878U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_981073619(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_System_LcGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
