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

}