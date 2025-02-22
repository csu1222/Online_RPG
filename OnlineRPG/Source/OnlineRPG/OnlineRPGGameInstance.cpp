// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineRPGGameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "PacketSession.h"
#include "Network/Protocol.pb.h"
#include "ClientPacketHandler.h"
#include "OR_MyPlayer.h"

void UOnlineRPGGameInstance::ConnectToGameServer()
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

void UOnlineRPGGameInstance::DisconnectFromGameServer()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	Protocol::C_LEAVE_GAME LeavePkt;
	SEND_PACKET(LeavePkt);

	//if (Socket)
	//{
	//	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
	//	SocketSubsystem->DestroySocket(Socket);
	//	Socket = nullptr;
	//}
}

void UOnlineRPGGameInstance::HandleRecvPackets()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->HandleRecvPackets();
}

void UOnlineRPGGameInstance::SendPacket(SendBufferRef SendBuffer)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->SendPacket(SendBuffer);
}

void UOnlineRPGGameInstance::HandleSpawn(const Protocol::ObjectInfo& ObjectInfo, bool IsMine)
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

	// �÷��̾� �������� ID üũ
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentPosInfo is nullptr, This Player ID : %llu"), ObjectInfo.object_id()));
	
	if (IsMine)
	{
		// �� ĳ����
		auto* PC = UGameplayStatics::GetPlayerController(this, 0);
		AOR_Player* Player = Cast<AOR_Player>(PC->GetPawn());
		if (Player == nullptr)
			return;

		Player->SetPlayerInfo(PosInfo);
		MyPlayer = Player;
		Players.Add(ObjectInfo.object_id(), Player);
	}
	else
	{
		// �ٸ� �÷��̾�
		AOR_Player* OtherPlayer = Cast<AOR_Player>(World->SpawnActor(OtherPlayerClass, &SpawnLocation));
		OtherPlayer->SetPlayerInfo(PosInfo);
		Players.Add(ObjectInfo.object_id(), OtherPlayer);
	}
}

void UOnlineRPGGameInstance::HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt)
{
	HandleSpawn(EnterGamePkt.player(), true);
}

void UOnlineRPGGameInstance::HandleSpawn(const Protocol::S_SPAWN& SpawnPkt)
{
	for (auto& Player : SpawnPkt.players())
	{
		HandleSpawn(Player, false);
	}
}

void UOnlineRPGGameInstance::HandleDespawn(uint64 ObjectId)
{
	// ���ϰ� ������ ������ ó������ ����
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	// ���尡 ������ ó������ ����
	auto* World = GetWorld();
	if (World == nullptr)
		return;

	// TODO : Despawn ó��

	// �÷��̾� ã��� Players�� ������ ó������ ����
	AOR_Player** FindActor = Players.Find(ObjectId);
	if (FindActor == nullptr)
		return;

	Players.Remove(ObjectId);

	World->DestroyActor(*FindActor);
}

void UOnlineRPGGameInstance::HandleDespawn(const Protocol::S_LEAVE_GAME& LeavePkt)
{
	uint64 ObjectId = LeavePkt.object_id();

	HandleDespawn(ObjectId);
}

void UOnlineRPGGameInstance::HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt)
{
	for (auto ObjectId : DespawnPkt.object_ids())
	{
		HandleDespawn(ObjectId);
	}
}

void UOnlineRPGGameInstance::HandleMove(const Protocol::S_MOVE& MovePkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = MovePkt.info().object_id();
	AOR_Player** FindActor = Players.Find(ObjectId);
	if (FindActor == nullptr)
		return;

	AOR_Player* Player = *FindActor;
	if (Player->IsMyPlayer())
		return;

	const Protocol::PosInfo& Info = MovePkt.info();
	Player->SetDestInfo(Info);
}
