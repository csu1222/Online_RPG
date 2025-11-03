// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Input/LcMappableConfigPair.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcMappableConfigPair() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UPlayerMappableInputConfig_NoRegister();
LC_5_5_API UScriptStruct* Z_Construct_UScriptStruct_FLcMappableConfigPair();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin ScriptStruct FLcMappableConfigPair
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_LcMappableConfigPair;
class UScriptStruct* FLcMappableConfigPair::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LcMappableConfigPair.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_LcMappableConfigPair.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLcMappableConfigPair, (UObject*)Z_Construct_UPackage__Script_LC_5_5(), TEXT("LcMappableConfigPair"));
	}
	return Z_Registration_Info_UScriptStruct_LcMappableConfigPair.OuterSingleton;
}
template<> LC_5_5_API UScriptStruct* StaticStruct<FLcMappableConfigPair>()
{
	return FLcMappableConfigPair::StaticStruct();
}
struct Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Input/LcMappableConfigPair.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "LcMappableConfigPair" },
		{ "ModuleRelativePath", "Input/LcMappableConfigPair.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldActivateAutomatically_MetaData[] = {
		{ "Category", "LcMappableConfigPair" },
		{ "ModuleRelativePath", "Input/LcMappableConfigPair.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Config;
	static void NewProp_bShouldActivateAutomatically_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldActivateAutomatically;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLcMappableConfigPair>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLcMappableConfigPair, Config), Z_Construct_UClass_UPlayerMappableInputConfig_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) };
void Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_bShouldActivateAutomatically_SetBit(void* Obj)
{
	((FLcMappableConfigPair*)Obj)->bShouldActivateAutomatically = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_bShouldActivateAutomatically = { "bShouldActivateAutomatically", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FLcMappableConfigPair), &Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_bShouldActivateAutomatically_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldActivateAutomatically_MetaData), NewProp_bShouldActivateAutomatically_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_Config,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewProp_bShouldActivateAutomatically,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
	nullptr,
	&NewStructOps,
	"LcMappableConfigPair",
	Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::PropPointers),
	sizeof(FLcMappableConfigPair),
	alignof(FLcMappableConfigPair),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLcMappableConfigPair()
{
	if (!Z_Registration_Info_UScriptStruct_LcMappableConfigPair.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_LcMappableConfigPair.InnerSingleton, Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_LcMappableConfigPair.InnerSingleton;
}
// End ScriptStruct FLcMappableConfigPair

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcMappableConfigPair_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLcMappableConfigPair::StaticStruct, Z_Construct_UScriptStruct_FLcMappableConfigPair_Statics::NewStructOps, TEXT("LcMappableConfigPair"), &Z_Registration_Info_UScriptStruct_LcMappableConfigPair, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLcMappableConfigPair), 3802773227U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcMappableConfigPair_h_2051786349(TEXT("/Script/LC_5_5"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcMappableConfigPair_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Input_LcMappableConfigPair_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
