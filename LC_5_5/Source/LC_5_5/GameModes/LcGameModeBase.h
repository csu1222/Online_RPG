// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LcGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LC_5_5_API ALcGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ALcGameModeBase();
	
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;


	/**
	 * member methods
	 */
	void HandleMatchAssignmentIfNotExpectingOne();
};
