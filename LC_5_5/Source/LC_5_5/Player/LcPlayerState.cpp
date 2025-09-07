// Fill out your copyright notice in the Description page of Project Settings.


#include "LcPlayerState.h"
#include "GameModes/LcExperienceManagerComponent.h"
#include "GameModes/LcGameModeBase.h"

void ALcPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	const AGameStateBase* GameState = GetWorld()->GetGameState();
	check(GameState);

	ULcExperienceManagerComponent* ExperienceManagerComponent = GameState->FindComponentByClass<ULcExperienceManagerComponent>();
	check(ExperienceManagerComponent);

	ExperienceManagerComponent->CallOrRegister_OnExperienceLoaded(FOnLcExperienceLoaded::FDelegate::CreateUObject(this, &ThisClass::OnExperienceLoaded));
}

void ALcPlayerState::OnExperienceLoaded(const ULcExperienceDefinition* CurrentExperience)
{
	if (ALcGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ALcGameModeBase>())
	{
		// ALcGameMode에서 GetPawnDataForController를 구현해야 함
		// - GetPawnDataForController에서 우리는 아직 PawnData를 설정하지 않았으므로, ExperienceMangerComponent의 DefaultPawnData로 설정한다
		const ULcPawnData* NewPawnData = GameMode->GetPawnDataForController(GetOwningController());
		check(NewPawnData);

		SetPawnData(NewPawnData);
	}
}


void ALcPlayerState::SetPawnData(const ULcPawnData* InPawnData)
{
	check(InPawnData);

	// PawnData가 두번 설정되는 것은 원하지 않음!
	check(!PawnData);

	PawnData = InPawnData;
}
