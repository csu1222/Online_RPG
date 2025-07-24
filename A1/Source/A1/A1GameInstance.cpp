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
	// TCP 소켓만들기
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));

	// 연결할 서버의 주소객체 만들기 
	FIPv4Address Ip;
	FIPv4Address::Parse(IpAddress, Ip);

	// 주소객체와 포트번호를 인터넨 어드레스 객체로 만들기 
	TSharedRef<FInternetAddr> InternetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddr->SetIp(Ip.Value);
	InternetAddr->SetPort(Port);

	// 잘 연결되었는지 로그찍기
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connecting To Server...")));

	// 연결시도
	bool Connected = Socket->Connect(*InternetAddr);

	// 연결시도 결과에 따라 진행
	if (Connected)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Success")));

		// Session
		GameServerSession = MakeShared<PacketSession>(Socket);
		GameServerSession->Run();

		// TEMP : Lobby에서 캐릭터 선택창 등
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

	// 중복 처리 체크
	const uint64 ObjectId = ObjectInfo.object_id();
	if (Players.Find(ObjectId) != nullptr)
		return;

	Protocol::PosInfo PosInfo = ObjectInfo.pos_info();
	FVector SpawnLocation(PosInfo.x(), PosInfo.y(), PosInfo.z());

	// 오브젝트 생성시점 ID 체크
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentPosInfo is nullptr, This Object ID : %llu"), ObjectInfo.object_id()));

	auto CreatureType = ObjectInfo.creature_info().creature_type();

	if (CreatureType == Protocol::CreatureType::CREATURE_TYPE_PLAYER)
	{
		if (IsMine)
		{
			// 내 캐릭터
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
			// 다른 플레이어
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

		// 몬스터 생성 전 좌표 로그
		{
			// 몬스터 오브젝트 아이디 로그
			UE_LOG(LogTemp, Error, TEXT("Monster Object ID: %llu"), ObjectInfo.object_id());

			// 몬스터 타입 로그
			FString CreatureTypeName = UTF8_TO_TCHAR(Protocol::CreatureType_Name(CreatureType).c_str());
			UE_LOG(LogTemp, Error, TEXT("Monster Creature Type: %s"), *CreatureTypeName);
			// 몬스터 PosInfo 로그
			UE_LOG(LogTemp, Error, TEXT("Monster PosInfo: X=%f, Y=%f, Z=%f"), PosInfo.x(), PosInfo.y(), PosInfo.z());
			
			// 몬스터 좌표 로그
			UE_LOG(LogTemp, Error, TEXT("Monster Spawn Location: X=%f, Y=%f, Z=%f"), SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);

			// 몬스터들의 좌표가 동일한지 확인
			for (const auto& Pair : Monsters)
			{
				AA1Monster* ExistingMonster = Pair.Value;
				FVector ExistingLocation = ExistingMonster->GetActorLocation();
				if (ExistingLocation.Equals(SpawnLocation, 0.01f)) // 오차 허용
				{
					UE_LOG(LogTemp, Warning, TEXT("동일한 위치에 몬스터가 이미 있습니다!"));


					// 필요하다면 return;
				}
			}
		}

		// 몬스터 생성
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
	// 소켓과 세션이 없으면 처리하지 않음
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	// 월드가 없으면 처리하지 않음
	auto* World = GetWorld();
	if (World == nullptr)
		return;

	// TODO : Despawn 처리

	{
		// 플레이어 찾기와 Players에 없으면 처리하지 않음
		AA1Player** FindActor = Players.Find(ObjectId);
		if (FindActor == nullptr)
			return;

		Players.Remove(ObjectId);

		World->DestroyActor(*FindActor);
	}
	{
		// 몬스터 찾기와 Monsters에 없으면 처리하지 않음
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
