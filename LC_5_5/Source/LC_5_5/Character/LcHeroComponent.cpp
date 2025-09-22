// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LcHeroComponent.h"
#include "LcPawnData.h"
#include "LcPawnExtensionComponent.h"
#include "Components/GameFrameworkComponentManager.h"
#include "LcGameplayTags.h"
#include "LcLogChannels.h"
#include "Lc_5_5/Player/LcPlayerState.h"

ULcHeroComponent::ULcHeroComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;
}
