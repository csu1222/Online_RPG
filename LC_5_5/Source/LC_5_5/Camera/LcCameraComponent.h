// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LcCameraMode.h"
#include "Camera/CameraComponent.h"
#include "LcCameraComponent.generated.h"

class ULcCameraModeStack;

/* 인자의 의미가 순서대로 (반환될 타입, 델리게이트의 이름) */
DECLARE_DELEGATE_RetVal(TSubclassOf<ULcCameraMode>, FLcCameraModeDelegate);
/**
 * 
 */
UCLASS()
class LC_5_5_API ULcCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
public:
	ULcCameraComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	static ULcCameraComponent* FindCameraComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<ULcCameraComponent>() : nullptr); }

	/*
		Member Method
	*/
	void UpdateCameraModes();

	/**
	 * CameraComponent interface
	 */
	virtual void OnRegister() final;
	virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) final;

	/**
	 * member variables
	 */
	 /** 카메라의 blending 기능을 지원하는 stack */
	UPROPERTY()
	TObjectPtr<ULcCameraModeStack> CameraModeStack;

	/* 카메라의 Blending 기능을 지원하는 Delegate */
	FLcCameraModeDelegate DetermineCameraModeDelegate;
};
