// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LcCameraMode.generated.h"

class ULcCameraComponent;

/**
 *
 */

 /* Camera Blending ��� ���� */
UCLASS()
class LC_5_5_API ULcCameraMode : public UObject
{
	GENERATED_BODY()
public:
	ULcCameraMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

/* Camera Blending�� ����ϴ� ��ü */
UCLASS()
class LC_5_5_API ULcCameraModeStack : public UObject
{
	GENERATED_BODY()
public:
	ULcCameraModeStack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	* member variables
	*/

	/** ������ CameraMode�� ���� */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeInstances;

	/** Camera Matrix Blend ������Ʈ ���� ť */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeStack;
};
