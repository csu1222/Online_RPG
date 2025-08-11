// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LcExperienceDefinition.generated.h"

class ULcPawnData;

/**
 * 
 */
UCLASS()
class LC_5_5_API ULcExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	ULcExperienceDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	 * member variables
	 */
	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TObjectPtr<ULcPawnData> DefaultPawnData;

	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TArray<FString> GameFeaturesToEnable;
};
