// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Protocol.pb.h"
#include "OR_Player.generated.h"

UCLASS()
class ONLINERPG_API AOR_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOR_Player();
	virtual ~AOR_Player();

protected:
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	bool IsMyPlayer();

	Protocol::MoveState GetMoveState() { return CurrentPosInfo->state(); }
	 void SetMoveState(Protocol::MoveState State);

public:
	void SetPlayerInfo(const Protocol::PosInfo& Info);
	void SetDestInfo(const Protocol::PosInfo& Info);
	Protocol::PosInfo* GetPlayerPosInfo() { return CurrentPosInfo; }

protected:
	class Protocol::PosInfo*		CurrentPosInfo;
	class Protocol::PosInfo*		DestPosInfo; // 목적지
	class Protocol::ObjectInfo*		PlayerInfo; // 플레이어 정보
};
