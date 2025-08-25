// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/LcGameModeBase.h"

#include "LcGameState.h"
#include "Player/LcPlayerController.h"
#include "Player/LcPlayerState.h"
#include "Character/LcCharacter.h"

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

	// ���� GameInstance�� ����, �ʱ�ȭ �۾��� ����ǹǷ�, �� �����ӿ��� Lyra�� Concept�� Experience ó���� ������ �� ����:
	// - �̸� ó���ϱ� ����, �������� �ڿ� �̺�Ʈ�� �޾� ó���� �̾ �����Ѵ�
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::HandleMatchAssignmentIfNotExpectingOne);
}

void ALcGameModeBase::HandleMatchAssignmentIfNotExpectingOne()
{
	// �ش� �Լ������� �츮�� �ε��� Experience�� ���� PrimaryAssetId�� �����Ͽ�, OnMatchAssignmentGiven���� �Ѱ��ش�

	FPrimaryAssetId ExperienceId;

	// precedence order (highest wins)
	// - matchmaking assignment (if present)
	// - default experience

	UWorld* World = GetWorld();

	// fall back to the default experience
	// �ϴ� �⺻ �ɼ����� default�ϰ� B_HakDefaultExperience�� ��������
	if (!ExperienceId.IsValid())
	{
		ExperienceId = FPrimaryAssetId(FPrimaryAssetType("HakExperienceDefinition"), FName("B_HakDefaultExperience"));
	}

	// ���ڰ� ������ HandleMatchAssignmentIfNotExpectingOne�� OnMatchAssignmentGiven()�� ���� ���������� �̸��� �ʹ��� �ʴ´ٰ� �����Ѵ�
	// - ����, ������� Lyra�� �����Ǹ�, �ش� �Լ��� ���� �� ������ �� ���� ������ �����Ѵ�
	//OnMatchAssignmentGiven(ExperienceId);
}
