// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "A1.h"
#include "A1GameInstance.generated.h"

class AA1Player;
class AA1Monster;
/**
 * 
 */
UCLASS()
class A1_API UA1GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ConnectToServer();

	UFUNCTION(BlueprintCallable)
	void DisconnectFromGameServer();

	UFUNCTION(BlueprintCallable)
	void HandleRecvPackets();

	void SendPacket(SendBufferRef SendBuffer);

public:
	// 패킷처리

	// HandleSpawn 3가지 버전
	void HandleSpawn(const Protocol::ObjectInfo& ObjectInfo, bool IsMine);
	void HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt);
	void HandleSpawn(const Protocol::S_SPAWN& SpawnPkt);

	void HandleDespawn(uint64 ObjectId);
	void HandleDespawn(const Protocol::S_LEAVE_GAME& LeavePkt);
	void HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt);

	void HandleMove(const Protocol::S_MOVE& MovePkt);

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT("127.0.0.1");
	int16 Port = 7777;
	TSharedPtr<class PacketSession> GameServerSession;
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AA1Player>		OtherPlayerClass;
	AA1Player* MyPlayer;
	TMap<uint64, AA1Player*>	Players;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AA1Monster>		MonsterClass;
	TMap<uint64, AA1Monster*>	Monsters;
};
