// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/LcCameraMode.h"
#include "LcCameraMode_ThirdPerson.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class LC_5_5_API ULcCameraMode_ThirdPerson : public ULcCameraMode
{
	GENERATED_BODY()
public:
	ULcCameraMode_ThirdPerson(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};
