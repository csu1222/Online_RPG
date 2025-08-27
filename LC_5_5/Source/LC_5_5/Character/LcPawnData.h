// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LcPawnData.generated.h"

/**
 * 
 */
UCLASS()
class LC_5_5_API ULcPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	ULcPawnData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** Pawn의 Class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lc|Pawn")
	TSubclassOf<APawn> PawnClass;
	
};
