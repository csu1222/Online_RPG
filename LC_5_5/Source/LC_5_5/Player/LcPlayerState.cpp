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
		// ALcGameMode���� GetPawnDataForController�� �����ؾ� ��
		// - GetPawnDataForController���� �츮�� ���� PawnData�� �������� �ʾ����Ƿ�, ExperienceMangerComponent�� DefaultPawnData�� �����Ѵ�
		const ULcPawnData* NewPawnData = GameMode->GetPawnDataForController(GetOwningController());
		check(NewPawnData);

		SetPawnData(NewPawnData);
	}
}


void ALcPlayerState::SetPawnData(const ULcPawnData* InPawnData)
{
	check(InPawnData);

	// PawnData�� �ι� �����Ǵ� ���� ������ ����!
	check(!PawnData);

	PawnData = InPawnData;
}
