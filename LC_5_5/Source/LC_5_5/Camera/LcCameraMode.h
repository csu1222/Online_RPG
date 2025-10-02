// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LcCameraMode.generated.h"

class ULcCameraComponent;

/**
 *
 */

 /* Camera Blending 대상 유닛 */
UCLASS()
class LC_5_5_API ULcCameraMode : public UObject
{
	GENERATED_BODY()
public:
	ULcCameraMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

/* Camera Blending을 담당하는 객체 */
UCLASS()
class LC_5_5_API ULcCameraModeStack : public UObject
{
	GENERATED_BODY()
public:
	ULcCameraModeStack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	* member variables
	*/

	/** 생성된 CameraMode를 관리 */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeInstances;

	/** Camera Matrix Blend 업데이트 진행 큐 */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeStack;
};
