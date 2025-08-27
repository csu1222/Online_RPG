// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LcPlayerState.generated.h"

class ULcPawnData;
class ULcExperienceDefinition;

/**
 * 
 */
UCLASS()
class LC_5_5_API ALcPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	/**
	 * AActor's interface
	 */
	virtual void PostInitializeComponents() final;

	/**
	 * member methods
	 */
	void OnExperienceLoaded(const ULcExperienceDefinition* CurrentExperience);

	UPROPERTY()
	TObjectPtr<const ULcPawnData> PawnData;
};
