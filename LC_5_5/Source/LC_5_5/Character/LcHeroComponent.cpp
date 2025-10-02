// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LcHeroComponent.h"
#include "LcPawnData.h"
#include "LcPawnExtensionComponent.h"
#include "Components/GameFrameworkComponentManager.h"
#include "LcGameplayTags.h"
#include "LcLogChannels.h"
 #include "Camera/LcCameraComponent.h"
#include "Lc_5_5/Player/LcPlayerState.h"

/** FeatureName 정의: static member variable 초기화 */
const FName ULcHeroComponent::NAME_ActorFeatureName("Hero");

ULcHeroComponent::ULcHeroComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;
}

void ULcHeroComponent::OnRegister()
{
	Super::OnRegister();

	// 올바른 Actor에 등록되었는지 확인:
	{
		if (!GetPawn<APawn>())
		{
			UE_LOG(LogLC, Error, TEXT("this component has been added to a BP whose base class is not a Pawn!"));
			return;
		}
	}

	RegisterInitStateFeature();
}

void ULcHeroComponent::BeginPlay()
{
	Super::BeginPlay();

	// PawnExtensionComponent에 대해서 (PawnExtension Feature) OnActorInitStateChanged() 관찰하도록 (Observing)
	BindOnActorInitStateChanged(ULcPawnExtensionComponent::NAME_ActorFeatureName, FGameplayTag(), false);

	// InitState_Spawned로 초기화
	ensure(TryToChangeInitState(FLcGameplayTags::Get().InitState_Spawned));

	// ForceUpdate 진행
	CheckDefaultInitialization();
}

void ULcHeroComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UnregisterInitStateFeature();

	Super::EndPlay(EndPlayReason);
}

void ULcHeroComponent::OnActorInitStateChanged(const FActorInitStateChangedParams& Params)
{
	const FLcGameplayTags& InitTags = FLcGameplayTags::Get();

	if (Params.FeatureName == ULcPawnExtensionComponent::NAME_ActorFeatureName)
	{
		// LcPawnExtensionComponent의 DataInitialized 상태 변화 관찰 후, LcHeroComponent도 DataInitialized 상태로 변경
		// - CanChangeInitState 확인
		if (Params.FeatureState == InitTags.InitState_DataInitialized)
		{
			CheckDefaultInitialization();
		}
	}
}

bool ULcHeroComponent::CanChangeInitState(UGameFrameworkComponentManager* Manager, FGameplayTag CurrentState, FGameplayTag DesiredState) const
{
	check(Manager);

	const FLcGameplayTags& InitTags = FLcGameplayTags::Get();
	APawn* Pawn = GetPawn<APawn>();
	ALcPlayerState* LcPS = GetPlayerState<ALcPlayerState>();

	// Spawned 초기화
	if (!CurrentState.IsValid() && DesiredState == InitTags.InitState_Spawned)
	{
		if (Pawn)
		{
			return true;
		}
	}

	// Spawned -> DataAvailable
	if (CurrentState == InitTags.InitState_Spawned && DesiredState == InitTags.InitState_DataAvailable)
	{
		if (!LcPS)
		{
			return false;
		}

		return true;
	}

	// DataAvailable -> DataInitialized
	if (CurrentState == InitTags.InitState_DataAvailable && DesiredState == InitTags.InitState_DataInitialized)
	{
		// PawnExtensionComponent가 DataInitialized될 때까지 기다림 (== 모든 Feature Component가 DataAvailable인 상태)
		return LcPS && Manager->HasFeatureReachedInitState(Pawn, ULcPawnExtensionComponent::NAME_ActorFeatureName, InitTags.InitState_DataInitialized);
	}

	// DataInitialized -> GameplayReady
	if (CurrentState == InitTags.InitState_DataInitialized && DesiredState == InitTags.InitState_GameplayReady)
	{
		return true;
	}

	return false;
}

void ULcHeroComponent::HandleChangeInitState(UGameFrameworkComponentManager* Manager, FGameplayTag CurrentState, FGameplayTag DesiredState)
{
	const FLcGameplayTags& InitTags = FLcGameplayTags::Get();

	// DataAvailable -> DataInitialized 단계
	if (CurrentState == InitTags.InitState_DataAvailable && DesiredState == InitTags.InitState_DataInitialized)
	{
		APawn* Pawn = GetPawn<APawn>();
		ALcPlayerState* LcPS = GetPlayerState<ALcPlayerState>();
		if (!ensure(Pawn && LcPS))
		{
			return;
		}

		// Input과 Camera에 대한 핸들링... (TODO)

		const bool bIsLocallyControlled = Pawn->IsLocallyControlled();
		const ULcPawnData* PawnData = nullptr;
		if (ULcPawnExtensionComponent* PawnExtComp = ULcPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
		{
			PawnData = PawnExtComp->GetPawnData<ULcPawnData>();
		}

		if (bIsLocallyControlled && PawnData)
		{
			// 현재 HakCharacter에 Attach된 CameraComponent를 찾음
			if (ULcCameraComponent* CameraComponent = ULcCameraComponent::FindCameraComponent(Pawn))
			{
				CameraComponent->DetermineCameraModeDelegate.BindUObject(this, &ThisClass::DetermineCameraMode);
			}
		}
	}
}

void ULcHeroComponent::CheckDefaultInitialization()
{
	// 앞서 BindOnActorInitStateChanged에서 보았듯이 Hero Feature는 Pawn Extension Feature에 종속되어 있으므로, CheckDefaultInitializationForImplementers 호출하지 않음:

	// ContinueInitStateChain은 앞서 PawnExtComponent와 같음
	const FLcGameplayTags& InitTags = FLcGameplayTags::Get();
	static const TArray<FGameplayTag> StateChain = { InitTags.InitState_Spawned, InitTags.InitState_DataAvailable, InitTags.InitState_DataInitialized, InitTags.InitState_GameplayReady };
	ContinueInitStateChain(StateChain);
}


PRAGMA_DISABLE_OPTIMIZATION
TSubclassOf<ULcCameraMode> ULcHeroComponent::DetermineCameraMode() const
{
	const APawn* Pawn = GetPawn<APawn>();
	if (!Pawn)
	{
		return nullptr;
	}

	if (ULcPawnExtensionComponent* PawnExtComp = ULcPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
	{
		if (const ULcPawnData* PawnData = PawnExtComp->GetPawnData<ULcPawnData>())
		{
			return PawnData->DefaultCameraMode;
		}
	}

	return nullptr;
}
PRAGMA_ENABLE_OPTIMIZATION