// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/A1Monster.h"
#include "A1AIController.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AA1Monster::AA1Monster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentPosInfo = new Protocol::PosInfo();
	DestPosInfo = new Protocol::PosInfo();
	MonsterInfo = new Protocol::ObjectInfo();
}

AA1Monster::~AA1Monster()
{
}

// Called when the game starts or when spawned
void AA1Monster::BeginPlay()
{
	Super::BeginPlay();

    // ����: ���� ���� �� Ư�� ��ġ�� �̵�
    FVector TargetLocation(1000.f, 1000.f, 0.f); // �̵��� ��ǥ ��ġ

    // AIController�� ���� �̵� ���
    AA1AIController* AIController = Cast<AA1AIController>(GetController());
    if (AIController)
    {
        AIController->MoveToLocation(TargetLocation);
    }
}

// Called every frame
void AA1Monster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA1Monster::SetMoveState(Protocol::MoveState State)
{
	if (CurrentPosInfo != nullptr)
	{
		CurrentPosInfo->set_state(State);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentPosInfo is nullptr, This Monster ID : %llu"), CurrentPosInfo->object_id()));
		return;
	}
}

void AA1Monster::SetMonsterPosInfo(const Protocol::PosInfo& Info)
{
	if (CurrentPosInfo->object_id() != 0)
	{
		assert(CurrentPosInfo->object_id() == Info.object_id());
	}

	if (CurrentPosInfo != nullptr)
	{
		CurrentPosInfo->CopyFrom(Info);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentPosInfo is nullptr, This Monster ID : %llu"), Info.object_id()));
		return;
	}


	FVector Location(Info.x(), Info.y(), Info.z());
	SetActorLocation(Location);
}

void AA1Monster::SetDestPosInfo(const Protocol::PosInfo& Info)
{
	if (CurrentPosInfo->object_id() != 0)
	{
		assert(CurrentPosInfo->object_id() == Info.object_id());
	}

	// Dest�� ���� ���� ����.
	DestPosInfo->CopyFrom(Info);

	// ���¸� �ٷ� ��������.
	SetMoveState(Info.state());
}

// Called to bind functionality to input
void AA1Monster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

