// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "LcExperienceManagerComponent.generated.h"

class ULcExperienceDefinition;

enum class ELcExperienceLoadState
{
	Unloaded,
	Loading,
	Loaded,
	Deactivating,
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnLcExperienceLoaded, const ULcExperienceDefinition*);

/**
 * HakExperienceManagerComponent
 * - �� �״��, �ش� component�� game state�� owner�� �����鼭, experience�� ���� ������ ������ �ִ� component�̴�
 * - �Ӹ� �ƴ϶�, manager��� �ܾ ���ԵǾ� �ֵ���, experience �ε� ���� ������Ʈ �� �̺�Ʈ�� �����Ѵ�
 */
UCLASS()
class LC_5_5_API ULcExperienceManagerComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	/**
	 * member methods
	 */
	bool IsExperienceLoaded() { return (LoadState == ELcExperienceLoadState::Loaded) && (CurrentExperience != nullptr); }

	/**
	 * �Ʒ��� OnExperienceLoaded�� ���ε��ϰų�, �̹� Experience �ε��� �Ϸ�Ǿ��ٸ� �ٷ� ȣ����
	 */
	void CallOrRegister_OnExperienceLoaded(FOnLcExperienceLoaded::FDelegate&& Delegate);

public:
	UPROPERTY()
	TObjectPtr<const ULcExperienceDefinition> CurrentExperience;

	/** Experience�� �ε� ���¸� ����͸� */
	ELcExperienceLoadState LoadState = ELcExperienceLoadState::Unloaded;

	/** Experience �ε��� �Ϸ�� ����, Broadcasting Delegate */
	FOnLcExperienceLoaded OnExperienceLoaded;
};
