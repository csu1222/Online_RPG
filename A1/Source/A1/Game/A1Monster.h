// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Protocol.pb.h"
#include "A1Monster.generated.h"

UCLASS()
class A1_API AA1Monster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AA1Monster();
	virtual ~AA1Monster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	Protocol::MoveState GetMoveState() const { return CurrentPosInfo->state(); }
	void SetMoveState(Protocol::MoveState State);

public:
	void SetMonsterPosInfo(const Protocol::PosInfo& Info);
	void SetDestPosInfo(const Protocol::PosInfo& Info);
	Protocol::PosInfo* GetMonsterPosInfo() { return CurrentPosInfo; }
public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	Protocol::PosInfo* CurrentPosInfo; // 현재 위치 정보
	Protocol::PosInfo* DestPosInfo; // 목적지 위치 정보
	Protocol::ObjectInfo* MonsterInfo; // 몬스터 정보
};
