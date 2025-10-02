// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LcHeroComponent.h"
#include "LcPawnData.h"
#include "LcPawnExtensionComponent.h"
#include "Components/GameFrameworkComponentManager.h"
#include "LcGameplayTags.h"
#include "LcLogChannels.h"
 #include "Camera/LcCameraComponent.h"
#include "Lc_5_5/Player/LcPlayerState.h"

/** FeatureName ����: static member variable �ʱ�ȭ */
const FName ULcHeroComponent::NAME_ActorFeatureName("Hero");

ULcHeroComponent::ULcHeroComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;
}

void ULcHeroComponent::OnRegister()
{
	Super::OnRegister();

	// �ùٸ� Actor�� ��ϵǾ����� Ȯ��:
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

	// PawnExtensionComponent�� ���ؼ� (PawnExtension Feature) OnActorInitStateChanged() �����ϵ��� (Observing)
	BindOnActorInitStateChanged(ULcPawnExtensionComponent::NAME_ActorFeatureName, FGameplayTag(), false);

	// InitState_Spawned�� �ʱ�ȭ
	ensure(TryToChangeInitState(FLcGameplayTags::Get().InitState_Spawned));

	// ForceUpdate ����
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
		// LcPawnExtensionComponent�� DataInitialized ���� ��ȭ ���� ��, LcHeroComponent�� DataInitialized ���·� ����
		// - CanChangeInitState Ȯ��
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

	// Spawned �ʱ�ȭ
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
		// PawnExtensionComponent�� DataInitialized�� ������ ��ٸ� (== ��� Feature Component�� DataAvailable�� ����)
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

	// DataAvailable -> DataInitialized �ܰ�
	if (CurrentState == InitTags.InitState_DataAvailable && DesiredState == InitTags.InitState_DataInitialized)
	{
		APawn* Pawn = GetPawn<APawn>();
		ALcPlayerState* LcPS = GetPlayerState<ALcPlayerState>();
		if (!ensure(Pawn && LcPS))
		{
			return;
		}

		// Input�� Camera�� ���� �ڵ鸵... (TODO)

		const bool bIsLocallyControlled = Pawn->IsLocallyControlled();
		const ULcPawnData* PawnData = nullptr;
		if (ULcPawnExtensionComponent* PawnExtComp = ULcPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
		{
			PawnData = PawnExtComp->GetPawnData<ULcPawnData>();
		}

		if (bIsLocallyControlled && PawnData)
		{
			// ���� HakCharacter�� Attach�� CameraComponent�� ã��
			if (ULcCameraComponent* CameraComponent = ULcCameraComponent::FindCameraComponent(Pawn))
			{
				CameraComponent->DetermineCameraModeDelegate.BindUObject(this, &ThisClass::DetermineCameraMode);
			}
		}
	}
}

void ULcHeroComponent::CheckDefaultInitialization()
{
	// �ռ� BindOnActorInitStateChanged���� ���ҵ��� Hero Feature�� Pawn Extension Feature�� ���ӵǾ� �����Ƿ�, CheckDefaultInitializationForImplementers ȣ������ ����:

	// ContinueInitStateChain�� �ռ� PawnExtComponent�� ����
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