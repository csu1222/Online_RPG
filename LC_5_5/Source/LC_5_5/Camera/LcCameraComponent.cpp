// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/LcCameraComponent.h"


ULcCameraComponent::ULcCameraComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), CameraModeStack(nullptr)
{
}

void ULcCameraComponent::UpdateCameraModes()
{
	check(CameraModeStack);

	// DetermineCameraModeDelegate는 CameraMode Class를 반환한다:
	// - 해당 delegate는 HeroComponent의 멤버 함수로 바인딩되어 있다
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
		// 초기화 (BeginPlay와 같은)가 딱히 필요없는 객체로 NewObject로 할당
		CameraModeStack = NewObject<ULcCameraModeStack>(this);
	}
}

void ULcCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
	Super::GetCameraView(DeltaTime, DesiredView);

	UpdateCameraModes();

	// EvaluateStack은 CameraModeStack에 있는 CameraMode를 업데이트(+블랜딩)하고 CameraModeStack을 Bottom-Top까지 업데이트된 CameraMode들을 Lerp를 진행해준다.
	// - 이에 대한 결과는 CameraModeView에 캐싱된다
	FLcCameraModeView CameraModeView;
	CameraModeStack->EvaluateStack(DeltaTime, CameraModeView);
}
