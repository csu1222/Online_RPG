// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/LcPlayerCameraManager.h"

ALcPlayerCameraManager::ALcPlayerCameraManager(const FObjectInitializer& ObjectInitializer)
{
	DefaultFOV = LC_CAMERA_DEFAULT_FOV;
	ViewPitchMin = LC_CAMERA_DEFAULT_PITCH_MIN;
	ViewPitchMax = LC_CAMERA_DEFAULT_PITCH_MAX;
}
