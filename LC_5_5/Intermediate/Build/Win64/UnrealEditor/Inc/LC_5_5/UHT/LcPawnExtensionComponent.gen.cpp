// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LC_5_5/Character/LcPawnExtensionComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcPawnExtensionComponent() {}

// Begin Cross Module References
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnData_NoRegister();
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnExtensionComponent();
LC_5_5_API UClass* Z_Construct_UClass_ULcPawnExtensionComponent_NoRegister();
MODULARGAMEPLAY_API UClass* Z_Construct_UClass_UGameFrameworkInitStateInterface_NoRegister();
MODULARGAMEPLAY_API UClass* Z_Construct_UClass_UPawnComponent();
UPackage* Z_Construct_UPackage__Script_LC_5_5();
// End Cross Module References

// Begin Class ULcPawnExtensionComponent
void ULcPawnExtensionComponent::StaticRegisterNativesULcPawnExtensionComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULcPawnExtensionComponent);
UClass* Z_Construct_UClass_ULcPawnExtensionComponent_NoRegister()
{
	return ULcPawnExtensionComponent::StaticClass();
}
struct Z_Construct_UClass_ULcPawnExtensionComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Character/LcPawnExtensionComponent.h" },
		{ "ModuleRelativePath", "Character/LcPawnExtensionComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnData_MetaData[] = {
		{ "Category", "Lc|Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Pawn\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb8\xef\xbf\xbd \xc4\xb3\xef\xbf\xbd\xef\xbf\xbd\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Character/LcPawnExtensionComponent.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pawn\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb8\xef\xbf\xbd \xc4\xb3\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PawnData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULcPawnExtensionComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULcPawnExtensionComponent_Statics::NewProp_PawnData = { "PawnData", nullptr, (EPropertyFlags)0x0114000000000801, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULcPawnExtensionComponent, PawnData), Z_Construct_UClass_ULcPawnData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnData_MetaData), NewProp_PawnData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULcPawnExtensionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULcPawnExtensionComponent_Statics::NewProp_PawnData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnExtensionComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULcPawnExtensionComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPawnComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LC_5_5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnExtensionComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ULcPawnExtensionComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UGameFrameworkInitStateInterface_NoRegister, (int32)VTABLE_OFFSET(ULcPawnExtensionComponent, IGameFrameworkInitStateInterface), false },  // 363983679
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULcPawnExtensionComponent_Statics::ClassParams = {
	&ULcPawnExtensionComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULcPawnExtensionComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnExtensionComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULcPawnExtensionComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULcPawnExtensionComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULcPawnExtensionComponent()
{
	if (!Z_Registration_Info_UClass_ULcPawnExtensionComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULcPawnExtensionComponent.OuterSingleton, Z_Construct_UClass_ULcPawnExtensionComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULcPawnExtensionComponent.OuterSingleton;
}
template<> LC_5_5_API UClass* StaticClass<ULcPawnExtensionComponent>()
{
	return ULcPawnExtensionComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULcPawnExtensionComponent);
ULcPawnExtensionComponent::~ULcPawnExtensionComponent() {}
// End Class ULcPawnExtensionComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnExtensionComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULcPawnExtensionComponent, ULcPawnExtensionComponent::StaticClass, TEXT("ULcPawnExtensionComponent"), &Z_Registration_Info_UClass_ULcPawnExtensionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULcPawnExtensionComponent), 1213720491U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnExtensionComponent_h_180363302(TEXT("/Script/LC_5_5"),
	Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnExtensionComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CPP_Game_Portfolio_LC_5_5_Source_LC_5_5_Character_LcPawnExtensionComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
