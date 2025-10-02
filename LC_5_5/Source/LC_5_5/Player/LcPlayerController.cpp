// Fill out your copyright notice in the Description page of Project Settings.


#include "LcPlayerController.h"
#include "LcPlayerCameraManager.h"

ALcPlayerController::ALcPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	 PlayerCameraManagerClass = ALcPlayerCameraManager::StaticClass();
}
