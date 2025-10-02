// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LcCameraMode.h"
#include "Camera/CameraComponent.h"
#include "LcCameraComponent.generated.h"

class ULcCameraModeStack;

/* ������ �ǹ̰� ������� (��ȯ�� Ÿ��, ��������Ʈ�� �̸�) */
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
	 /** ī�޶��� blending ����� �����ϴ� stack */
	UPROPERTY()
	TObjectPtr<ULcCameraModeStack> CameraModeStack;

	/* ī�޶��� Blending ����� �����ϴ� Delegate */
	FLcCameraModeDelegate DetermineCameraModeDelegate;
};
