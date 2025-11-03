// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LcMappableConfigPair.generated.h"

/** forward declaration */
class UPlayerMappableInputConfig;

USTRUCT()
struct FLcMappableConfigPair
{
	GENERATED_BODY()
public:
	FLcMappableConfigPair() = default;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	UPROPERTY(EditAnywhere)
	bool bShouldActivateAutomatically = true;
};