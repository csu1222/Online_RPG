// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LcCameraMode.generated.h"

class ULcCameraComponent;

/**
 * FLcCameraModeView
 */
struct FLcCameraModeView
{
	FLcCameraModeView();

	void Blend(const FLcCameraModeView& Other, float OtherWeight);

	FVector Location;
	FRotator Rotation;
	FRotator ControlRotation;
	float FieldOfView;
};

/**
 * [0,1]�� BlendFunction�� �°� ������� ���� Ÿ��
 */
UENUM(BlueprintType)
enum class ELcCameraModeBlendFunction : uint8
{
	Linear,
	/**
	 * EaseIn/Out�� exponent ���� ���� �����ȴ�:
	 */
	EaseIn,
	EaseOut,
	EaseInOut,
	COUNT
};

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

	 /** CameraMode�� ���� ������ CameraModeView */
	FLcCameraModeView View;

	/** Camera Mode�� FOV */
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "5.0", UIMax = "170", ClampMin = "5.0", Clampmax = "170.0"))
	float FieldOfView;

	/** View�� ���� Pitch [Min, Max] */
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", Clampmax = "89.9"))
	float ViewPitchMin;

	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", Clampmax = "89.9"))
	float ViewPitchMax;

	/** �󸶵��� Blend�� �������� �ð��� �ǹ� */
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendTime;

	/** �������� Blend �� [0, 1] */
	float BlendAlpha;

	/**
	 * �ش� CameraMode�� ���� Blend ��
	 * �ռ� BlendAlpha�� ���� ���� �����Ͽ� ���� BlendWeight�� ��� (�ڵ带 ����, �����غ���)
	 */
	float BlendWeight;

	/**
	* EaseIn/Out�� ����� Exponent
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendExponent;

	/** Blend function */
	ELcCameraModeBlendFunction BlendFunction;

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
	ULcCameraMode* GetCameraModeInstance(TSubclassOf<ULcCameraMode>& CameraModeClass);
	void PushCameraMode(TSubclassOf<ULcCameraMode>& CameraModeClass);
	void EvaluateStack(float DeltaTime, FLcCameraModeView& OutCameraModeView);
	void UpdateStack(float DeltaTime);
	void BlendStack(FLcCameraModeView& OutCameraModeView) const;
	
	/** ������ CameraMode�� ���� */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeInstances;

	/** Camera Matrix Blend ������Ʈ ���� ť */
	UPROPERTY()
	TArray<TObjectPtr<ULcCameraMode>> CameraModeStack;
};
