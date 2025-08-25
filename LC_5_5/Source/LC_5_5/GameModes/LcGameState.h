// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LcGameState.generated.h"

class ULcExperienceManagerComponent;
/**
 * 
 */
UCLASS()
class LC_5_5_API ALcGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ALcGameState();

public:
	UPROPERTY()
	TObjectPtr<ULcExperienceManagerComponent> ExperienceManagerComponent;
	
};
