// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/OR_Player.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "OR_MyPlayer.h"
#include "OnlineRPGGameInstance.h"

// Sets default values
AOR_Player::AOR_Player()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	GetCharacterMovement()->bRunPhysicsWithNoController = true;

	CurrentPosInfo = new Protocol::PosInfo();
	DestPosInfo = new Protocol::PosInfo();
	PlayerInfo = new Protocol::ObjectInfo();

}

AOR_Player::~AOR_Player()
{
	delete CurrentPosInfo;
	delete DestPosInfo;
	delete PlayerInfo;
	CurrentPosInfo = nullptr;
	DestPosInfo = nullptr;
	PlayerInfo = nullptr;
}

// Called when the game starts or when spawned
void AOR_Player::BeginPlay()
{
	Super::BeginPlay();

	{
		FVector Location = GetActorLocation();
		DestPosInfo->set_x(Location.X);
		DestPosInfo->set_y(Location.Y);
		DestPosInfo->set_z(Location.Z);
		DestPosInfo->set_yaw(GetControlRotation().Yaw);

		SetMoveState(Protocol::MOVE_STATE_IDLE);
	}
}

// Called every frame
void AOR_Player::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	{
		FVector Location = GetActorLocation();
		CurrentPosInfo->set_x(Location.X);
		CurrentPosInfo->set_y(Location.Y);
		CurrentPosInfo->set_z(Location.Z);
		CurrentPosInfo->set_yaw(GetControlRotation().Yaw);
	}

	if (IsMyPlayer() == false)
	{
		//FVector Location = GetActorLocation();
		//FVector DestLocation = FVector(DestInfo->x(), DestInfo->y(), DestInfo->z());

		//FVector MoveDir = (DestLocation - Location);
		//const float DistToDest = MoveDir.Length();
		//MoveDir.Normalize();

		//float MoveDist = (MoveDir * 600.f * DeltaSeconds).Length();
		//MoveDist = FMath::Min(MoveDist, DistToDest);
		//FVector NextLocation = Location + MoveDir* MoveDist;

		//SetActorLocation(NextLocation);
		
		const Protocol::MoveState State = CurrentPosInfo->state();

		if (State == Protocol::MOVE_STATE_RUN)
		{
			SetActorRotation(FRotator(0, DestPosInfo->yaw(), 0));
			AddMovementInput(GetActorForwardVector());
		}
		else
		{

		}
	}

}

bool AOR_Player::IsMyPlayer()
{
	return Cast<AOR_MyPlayer>(this) != nullptr;
}


void AOR_Player::SetMoveState(Protocol::MoveState State)
{
	if (CurrentPosInfo->state() == State)
		return;

	CurrentPosInfo->set_state(State);

	// TODO
}

void AOR_Player::SetPlayerInfo(const Protocol::PosInfo& Info)
{
	if (CurrentPosInfo->object_id() != 0)
	{
		assert(CurrentPosInfo->object_id() == Info.object_id());
	}

	CurrentPosInfo->CopyFrom(Info);

	FVector Location(Info.x(), Info.y(), Info.z());
	SetActorLocation(Location);
}

void AOR_Player::SetDestInfo(const Protocol::PosInfo& Info)
{
	if (CurrentPosInfo->object_id() != 0)
	{
		assert(CurrentPosInfo->object_id() == Info.object_id());
	}

	// Dest에 최종 상태 복사.
	DestPosInfo->CopyFrom(Info);

	// 상태만 바로 적용하자.
	SetMoveState(Info.state());
}


