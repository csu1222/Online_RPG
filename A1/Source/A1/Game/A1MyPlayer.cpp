// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/A1MyPlayer.h"
//#include "Game/OR_Env_ItrAble.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "A1.h"
#include "Kismet/KismetMathLibrary.h"
#include "typeinfo"
#include "A1MyPlayer.h"

AA1MyPlayer::AA1MyPlayer()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AA1MyPlayer::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AA1MyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AA1MyPlayer::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AA1MyPlayer::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AA1MyPlayer::Look);

		//Interate
		EnhancedInputComponent->BindAction(InteracteAction, ETriggerEvent::Triggered, this, &AA1MyPlayer::Interacte);
		EnhancedInputComponent->BindAction(InteracteAction, ETriggerEvent::Completed, this, &AA1MyPlayer::Interacte);
	}

}

void AA1MyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Send 판정
	bool ForceSendPacket = false;

	if (LastDesiredInput != DesiredInput)
	{
		ForceSendPacket = true;
		LastDesiredInput = DesiredInput;
	}

	// State 정보
	if (DesiredInput == FVector2D::Zero())
		SetMoveState(Protocol::MOVE_STATE_IDLE);
	else
		SetMoveState(Protocol::MOVE_STATE_RUN);

	MovePacketSendTimer -= DeltaTime;

	if (MovePacketSendTimer <= 0 || ForceSendPacket)
	{
		MovePacketSendTimer = MOVE_PACKET_SEND_DELAY;

		Protocol::C_MOVE MovePkt;

		// 현재 위치 정보
		{
			Protocol::PosInfo* Info = MovePkt.mutable_info();
			Info->CopyFrom(*CurrentPosInfo);
			Info->set_yaw(DesiredYaw);
			Info->set_state(GetMoveState());
		}

		SEND_PACKET(MovePkt);
	}
}

void AA1MyPlayer::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);

		// Cache
		{
			DesiredInput = MovementVector;

			DesiredMoveDirection = FVector::ZeroVector;
			DesiredMoveDirection += ForwardDirection * MovementVector.Y;
			DesiredMoveDirection += RightDirection * MovementVector.X;
			DesiredMoveDirection.Normalize();

			const FVector Location = GetActorLocation();
			FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(Location, Location + DesiredMoveDirection);
			DesiredYaw = Rotator.Yaw;
		}
	}
}

void AA1MyPlayer::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AA1MyPlayer::Interacte(const FInputActionValue& Value)
{
	bool bInteratePressed = Value.Get<bool>();

	if (Controller != nullptr)
	{
		if (bInteratePressed)
		{
			// Interate
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Interacte Input Down...")));

			//// lay cast
			//CheckAimedObject();
		}
		else
		{
			// Stop Interate
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Interacte Input Up...")));
		}
	}
}

//void AA1MyPlayer::CheckAimedObject()
//{
//	// Trace
//	FHitResult HitResult;
//	const FVector PlayerLocation = GetActorLocation();
//	const FVector Start = FollowCamera->GetComponentLocation();
//	const FVector End = Start + FollowCamera->GetForwardVector() * Aimed_Range;
//	FCollisionQueryParams CollisionParams;
//	CollisionParams.AddIgnoredActor(this);
//	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
//	{
//		if (HitResult.GetActor()->IsValidLowLevel())
//		{
//			// TODO : Aimed 처리
//
//			// Debug, Hit Actor, Range
//			AActor* HitActor = HitResult.GetActor();
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit Actor : %s"), *HitActor->GetName()));
//
//			// Hit 된 Actor의 클래스를 확인
//			AOR_Env_ItrAble* ItrAble = Cast<AOR_Env_ItrAble>(HitActor);
//			bool CanCast = (ItrAble != nullptr);
//
//			// log
//			auto* HitedClass = HitActor->GetClass();
//			float HitedRange = GetDistanceBetweenMeAndTarget(HitResult);
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hited Actor class : %s, Hited Range : %f, Cast Result : %s"), *HitActor->GetName(), HitedRange, CanCast ? TEXT("true") : TEXT("false")));
//		}
//	}
//}
//
//float AA1MyPlayer::GetDistanceBetweenMeAndTarget(const FHitResult HitResult)
//{
//	const FVector PlayerLocation = GetActorLocation();
//	FVector HitLocation = HitResult.ImpactPoint;
//
//	return (HitLocation - PlayerLocation).Size();
//}
//
//bool AA1MyPlayer::CanInteracte(const FHitResult HitResult, AOR_Env_ItrAble* Interactable)
//{
//	bool Result = false;
//	AActor* HitActor = HitResult.GetActor();
//	AOR_Env_ItrAble* ItrAble = Cast<AOR_Env_ItrAble>(HitActor);
//	if (ItrAble != nullptr)
//	{
//		Result = true;
//	}
//	return Result;
//}
