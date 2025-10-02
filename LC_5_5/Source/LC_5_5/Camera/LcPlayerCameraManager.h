// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "LcPlayerCameraManager.generated.h"

/*
*	Controller에 바인딩된 CameraManager
*/
#define LC_CAMERA_DEFAULT_FOV (80.0f)
#define LC_CAMERA_DEFAULT_PITCH_MIN (-89.0f)
#define LC_CAMERA_DEFAULT_PITCH_MAX (89.0f)

/**
 * 
 */
UCLASS()
class LC_5_5_API ALcPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
public:
	ALcPlayerCameraManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};
