// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/LcCameraComponent.h"


ULcCameraComponent::ULcCameraComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), CameraModeStack(nullptr)
{
}

void ULcCameraComponent::UpdateCameraModes()
{
	check(CameraModeStack);

	// DetermineCameraModeDelegate�� CameraMode Class�� ��ȯ�Ѵ�:
	// - �ش� delegate�� HeroComponent�� ��� �Լ��� ���ε��Ǿ� �ִ�
	if (DetermineCameraModeDelegate.IsBound())
	{
		if (TSubclassOf<ULcCameraMode> CameraMode = DetermineCameraModeDelegate.Execute())
		{
			CameraModeStack->PushCameraMode(CameraMode);
		}
	}
}

void ULcCameraComponent::OnRegister()
{
	Super::OnRegister();

	if (!CameraModeStack)
	{
		// �ʱ�ȭ (BeginPlay�� ����)�� ���� �ʿ���� ��ü�� NewObject�� �Ҵ�
		CameraModeStack = NewObject<ULcCameraModeStack>(this);
	}
}

void ULcCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
	Super::GetCameraView(DeltaTime, DesiredView);

	UpdateCameraModes();

	// EvaluateStack�� CameraModeStack�� �ִ� CameraMode�� ������Ʈ(+����)�ϰ� CameraModeStack�� Bottom-Top���� ������Ʈ�� CameraMode���� Lerp�� �������ش�.
	// - �̿� ���� ����� CameraModeView�� ĳ�̵ȴ�
	FLcCameraModeView CameraModeView;
	CameraModeStack->EvaluateStack(DeltaTime, CameraModeView);
}
