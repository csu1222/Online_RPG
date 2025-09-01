// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/LcGameModeBase.h"
#include "GameModes/LcExperienceDefinition.h"
#include "GameModes/LcExperienceManagerComponent.h"
#include "LcGameState.h"
#include "LcLogChannels.h"
#include "Player/LcPlayerController.h"
#include "Player/LcPlayerState.h"
#include "Character/LcCharacter.h"
#include "Character/LcPawnData.h"

ALcGameModeBase::ALcGameModeBase()
{

	GameStateClass = ALcGameState::StaticClass();
	PlayerControllerClass = ALcPlayerController::StaticClass();
	PlayerStateClass = ALcPlayerState::StaticClass();
	DefaultPawnClass = ALcCharacter::StaticClass();
}

void ALcGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	// 아직 GameInstance를 통해, 초기화 작업이 진행되므로, 현 프레임에는 Lyra의 Concept인 Experience 처리를 진행할 수 없다:
	// - 이를 처리하기 위해, 한프레임 뒤에 이벤트를 받아 처리를 이어서 진행한다
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::HandleMatchAssignmentIfNotExpectingOne);
}

void ALcGameModeBase::InitGameState()
{
	Super::InitGameState();

	// Experience 비동기 로딩을 위한 Delegate를 준비한다:
	ULcExperienceManagerComponent* ExperienceManagerComponent = GameState->FindComponentByClass<ULcExperienceManagerComponent>();
	check(ExperienceManagerComponent);

	// OnExperienceLoaded 등록
	ExperienceManagerComponent->CallOrRegister_OnExperienceLoaded(FOnLcExperienceLoaded::FDelegate::CreateUObject(this, &ThisClass::OnExperienceLoaded));
}

PRAGMA_DISABLE_OPTIMIZATION
void ALcGameModeBase::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	if (IsExperienceLoaded())
	{
		Super::HandleStartingNewPlayer_Implementation(NewPlayer);
	}
}
PRAGMA_ENABLE_OPTIMIZATION

APawn* ALcGameModeBase::SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform)
{
	UE_LOG(LogLC, Log, TEXT("SpawnDefaultPawnAtTransform_Implementation is called!"));
	return Super::SpawnDefaultPawnAtTransform_Implementation(NewPlayer, SpawnTransform);
}

void ALcGameModeBase::HandleMatchAssignmentIfNotExpectingOne()
{
	// 해당 함수에서는 우리가 로딩할 Experience에 대해 PrimaryAssetId를 생성하여, OnMatchAssignmentGiven으로 넘겨준다

	FPrimaryAssetId ExperienceId;

	// precedence order (highest wins)
	// - matchmaking assignment (if present)
	// - default experience

	UWorld* World = GetWorld();

	// fall back to the default experience
	// 일단 기본 옵션으로 default하게 B_LcDefaultExperience로 설정놓자
	if (!ExperienceId.IsValid())
	{
		ExperienceId = FPrimaryAssetId(FPrimaryAssetType("LcExperienceDefinition"), FName("B_LcDefaultExperience"));
	}

	// 필자가 이해한 HandleMatchAssignmentIfNotExpectingOne과 OnMatchAssignmentGiven()은 아직 직관적으로 이름이 와닫지 않는다고 생각한다
	// - 후일, 어느정도 Lyra가 구현되면, 해당 함수의 명을 더 이해할 수 있을 것으로 예상한다
	OnMatchAssignmentGiven(ExperienceId);
}

void ALcGameModeBase::OnMatchAssignmentGiven(FPrimaryAssetId ExperienceId)
{
	// 해당 함수는 ExperienceManagerComponent을 활용하여 Experience을 로딩하기 위해, ExperienceManagerComponent의 ServerSetCurrentExperience를 호출한다

	check(ExperienceId.IsValid());

	ULcExperienceManagerComponent* ExperienceManagerComponent = GameState->FindComponentByClass<ULcExperienceManagerComponent>();
	check(ExperienceManagerComponent);
	ExperienceManagerComponent->ServerSetCurrentExperience(ExperienceId);
}

bool ALcGameModeBase::IsExperienceLoaded() const
{
	check(GameState);
	ULcExperienceManagerComponent* ExperienceManagerComponent = GameState->FindComponentByClass<ULcExperienceManagerComponent>();
	check(ExperienceManagerComponent);

	return ExperienceManagerComponent->IsExperienceLoaded();
}

void ALcGameModeBase::OnExperienceLoaded(const ULcExperienceDefinition* CurrentExperience)
{
	// PlayerController를 순회하며
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PC = Cast<APlayerController>(*Iterator);

		// PlayerController가 Pawn을 Possess하지 않았다면, RestartPlayer를 통해 Pawn을 다시 Spawn한다
		// - 한번 OnPossess를 보도록 하자:
		if (PC && PC->GetPawn() == nullptr)
		{
			if (PlayerCanRestart(PC))
			{
				RestartPlayer(PC);
			}
		}
	}
}
