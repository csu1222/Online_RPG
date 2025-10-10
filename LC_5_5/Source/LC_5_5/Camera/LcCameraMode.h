// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LcCameraMode.generated.h"

/**
 * FLcCameraModeView
 */
struct FLcCameraModeView
{
	FLcCameraModeView();

	//void Blend(const FLcCameraModeView& Other, float OtherWeight);

	FVector Location;
	FRotator Rotation;
	FRotator ControlRotation;
	float FieldOfView;
};

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

	/**
	 * member methods
	 */
	void UpdateCameraMode(float DeltaTime);
	virtual void UpdateView(float DeltaTime);
	void UpdateBlending(float DeltaTime);

	ULcCameraComponent* GetLcCameraComponent() const;
	AActor* GetTargetActor() const;
	FVector GetPivotLocation() const;
	FRotator GetPivotRotation() const;

	/**
	 * member variables
	 */

	 /** CameraMode에 의해 생성된 CameraModeView */
	FLcCameraModeView View;

	/** Camera Mode의 FOV */
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "5.0", UIMax = "170", ClampMin = "5.0", Clampmax = "170.0"))
	float FieldOfView;

	/** View에 대한 Pitch [Min, Max] */
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", Clampmax = "89.9"))
	float ViewPitchMin;

	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", Clampmax = "89.9"))
	float ViewPitchMax;

	/** 얼마동안 Blend를 진행할지 시간을 의미 */
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendTime;

	/** 선형적인 Blend 값 [0, 1] */
	float BlendAlpha;

	/**
	 * 해당 CameraMode의 최종 Blend 값
	 * 앞서 BlendAlpha의 선형 값을 매핑하여 최종 BlendWeight를 계산 (코드를 보며, 이해해보자)
	 */
	float BlendWeight;

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
	ULcCameraMode* GetCameraModeInstance(TSubclassOf<ULcCameraMode>& CameraModeClass);
	void PushCameraMode(TSubclassOf<ULcCameraMode>& CameraModeClass);
	void EvaluateStack(float DeltaTime, FLcCameraModeView& OutCameraModeView);
	void UpdateStack(float DeltaTime);
	void BlendStack(FLcCameraModeView& OutCameraModeView) const;
	
	/** 생성된 CameraMode를 관리 */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeInstances;

	/** Camera Matrix Blend 업데이트 진행 큐 */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeStack;
};
