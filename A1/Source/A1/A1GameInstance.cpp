// Fill out your copyright notice in the Description page of Project Settings.


#include "A1GameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "PacketSession.h"
#include "Network/Protocol.pb.h"
#include "ClientPacketHandler.h"
#include "A1MyPlayer.h"
#include "A1Monster.h"

void UA1GameInstance::ConnectToServer()
{
	// TCP ���ϸ����
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));

	// ������ ������ �ּҰ�ü ����� 
	FIPv4Address Ip;
	FIPv4Address::Parse(IpAddress, Ip);

	// �ּҰ�ü�� ��Ʈ��ȣ�� ���ͳ� ��巹�� ��ü�� ����� 
	TSharedRef<FInternetAddr> InternetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddr->SetIp(Ip.Value);
	InternetAddr->SetPort(Port);

	// �� ����Ǿ����� �α����
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connecting To Server...")));

	// ����õ�
	bool Connected = Socket->Connect(*InternetAddr);

	// ����õ� ����� ���� ����
	if (Connected)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Success")));

		// Session
		GameServerSession = MakeShared<PacketSession>(Socket);
		GameServerSession->Run();

		// TEMP : Lobby���� ĳ���� ����â ��
		{
			Protocol::C_LOGIN pkt;
			SendBufferRef SendBuffer = ClientPacketHandler::MakeSendBuffer(pkt);
			SendPacket(SendBuffer);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Failed")));
	}
}

void UA1GameInstance::DisconnectFromGameServer()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	Protocol::C_LEAVE_GAME LeavePkt;
	SEND_PACKET(LeavePkt);
}

void UA1GameInstance::HandleRecvPackets()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->HandleRecvPackets();
}

void UA1GameInstance::SendPacket(SendBufferRef SendBuffer)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->SendPacket(SendBuffer);
}

void UA1GameInstance::HandleSpawn(const Protocol::ObjectInfo& ObjectInfo, bool IsMine)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	// �ߺ� ó�� üũ
	const uint64 ObjectId = ObjectInfo.object_id();
	if (Players.Find(ObjectId) != nullptr)
		return;

	Protocol::PosInfo PosInfo = ObjectInfo.pos_info();
	FVector SpawnLocation(PosInfo.x(), PosInfo.y(), PosInfo.z());

	// ������Ʈ �������� ID üũ
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentPosInfo is nullptr, This Object ID : %llu"), ObjectInfo.object_id()));

	auto CreatureType = ObjectInfo.creature_info().creature_type();

	if (CreatureType == Protocol::CreatureType::CREATURE_TYPE_PLAYER)
	{
		if (IsMine)
		{
			// �� ĳ����
			auto* PC = UGameplayStatics::GetPlayerController(this, 0);
			AA1Player* Player = Cast<AA1Player>(PC->GetPawn());
			if (Player == nullptr)
				return;

			Player->SetPlayerPosInfo(PosInfo);
			MyPlayer = Player;
			Players.Add(ObjectInfo.object_id(), Player);
		}
		else
		{
			// �ٸ� �÷��̾�
			AA1Player* OtherPlayer = Cast<AA1Player>(World->SpawnActor(OtherPlayerClass, &SpawnLocation));
			OtherPlayer->SetPlayerPosInfo(PosInfo);
			Players.Add(ObjectInfo.object_id(), OtherPlayer);
		}
	}
	else if (CreatureType == Protocol::CreatureType::CREATURE_TYPE_MONSTER)
	{
		if (MonsterClass == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("MonsterClass is null!"));
		}
		if (!MonsterClass->IsChildOf(AA1Monster::StaticClass()))
		{
			UE_LOG(LogTemp, Error, TEXT("MonsterClass is not a subclass of AA1Monster!"));
		}

		// ���� ���� �� ��ǥ �α�
		{
			// ���� ������Ʈ ���̵� �α�
			UE_LOG(LogTemp, Error, TEXT("Monster Object ID: %llu"), ObjectInfo.object_id());

			// ���� Ÿ�� �α�
			FString CreatureTypeName = UTF8_TO_TCHAR(Protocol::CreatureType_Name(CreatureType).c_str());
			UE_LOG(LogTemp, Error, TEXT("Monster Creature Type: %s"), *CreatureTypeName);
			// ���� PosInfo �α�
			UE_LOG(LogTemp, Error, TEXT("Monster PosInfo: X=%f, Y=%f, Z=%f"), PosInfo.x(), PosInfo.y(), PosInfo.z());
			
			// ���� ��ǥ �α�
			UE_LOG(LogTemp, Error, TEXT("Monster Spawn Location: X=%f, Y=%f, Z=%f"), SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);

			// ���͵��� ��ǥ�� �������� Ȯ��
			for (const auto& Pair : Monsters)
			{
				AA1Monster* ExistingMonster = Pair.Value;
				FVector ExistingLocation = ExistingMonster->GetActorLocation();
				if (ExistingLocation.Equals(SpawnLocation, 0.01f)) // ���� ���
				{
					UE_LOG(LogTemp, Warning, TEXT("������ ��ġ�� ���Ͱ� �̹� �ֽ��ϴ�!"));


					// �ʿ��ϴٸ� return;
				}
			}
		}

		// ���� ����
		AA1Monster* Monster = Cast<AA1Monster>(World->SpawnActor(MonsterClass, &SpawnLocation));
		Monster->SetMonsterPosInfo(PosInfo);
		Monsters.Add(ObjectInfo.object_id(), Monster);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Unknown Creature Type : %d"), static_cast<int32>(CreatureType)));
		return;
	}
}

void UA1GameInstance::HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt)
{
	HandleSpawn(EnterGamePkt.player(), true);
}

void UA1GameInstance::HandleSpawn(const Protocol::S_SPAWN& SpawnPkt)
{
	for (auto& Object : SpawnPkt.objects())
	{
		HandleSpawn(Object, false);
	}
}

void UA1GameInstance::HandleDespawn(uint64 ObjectId)
{
	// ���ϰ� ������ ������ ó������ ����
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	// ���尡 ������ ó������ ����
	auto* World = GetWorld();
	if (World == nullptr)
		return;

	// TODO : Despawn ó��

	{
		// �÷��̾� ã��� Players�� ������ ó������ ����
		AA1Player** FindActor = Players.Find(ObjectId);
		if (FindActor == nullptr)
			return;

		Players.Remove(ObjectId);

		World->DestroyActor(*FindActor);
	}
	{
		// ���� ã��� Monsters�� ������ ó������ ����
		AA1Monster** FindMonster = Monsters.Find(ObjectId);
		if (FindMonster == nullptr)
			return;
		Monsters.Remove(ObjectId);
		World->DestroyActor(*FindMonster);
	}
}

void UA1GameInstance::HandleDespawn(const Protocol::S_LEAVE_GAME& LeavePkt)
{
	uint64 ObjectId = LeavePkt.object_id();

	HandleDespawn(ObjectId);
}

void UA1GameInstance::HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt)
{
	for (auto ObjectId : DespawnPkt.object_ids())
	{
		HandleDespawn(ObjectId);
	}
}

void UA1GameInstance::HandleMove(const Protocol::S_MOVE& MovePkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = MovePkt.info().object_id();
	AA1Player** FindActor = Players.Find(ObjectId);
	if (FindActor == nullptr)
		return;

	AA1Player* Player = *FindActor;
	if (Player->IsMyPlayer())
		return;

	const Protocol::PosInfo& Info = MovePkt.info();
	Player->SetDestPosInfo(Info);
}
