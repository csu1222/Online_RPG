// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LcGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LC_5_5_API ULcGameInstance : public UGameInstance
{
	GENERATED_BODY()

	/**
	 * UGameInstance's interfaces
	 */
	virtual void Init() override;
	virtual void Shutdown() override;
};
