// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


// 언리얼 기본 헤더
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "CoreUObject.h"
#include "Engine.h"
#include "InputCore.h"
#include "Sockets.h"
#include "Networking.h"

// 인게임 공유 헤더
#include "OR_Env_ItrAble.h"

struct PacketHeader
{
	uint16 size;
	uint16 id; // 프로토콜ID (ex. 1=로그인, 2=이동요청)
};

class SendBuffer : public TSharedFromThis<SendBuffer>
{
public:
	SendBuffer(int32 bufferSize);
	~SendBuffer();

	BYTE* Buffer() { return _buffer.GetData(); }
	int32 WriteSize() { return _writeSize; }
	int32 Capacity() { return static_cast<int32>(_buffer.Num()); }

	void CopyData(void* data, int32 len);
	void Close(uint32 writeSize);

private:
	TArray<BYTE>	_buffer;
	int32			_writeSize = 0;
};


#define USING_SHARED_PTR(name)	using name##Ref = TSharedPtr<class name>;

USING_SHARED_PTR(Session);
USING_SHARED_PTR(PacketSession);
USING_SHARED_PTR(SendBuffer);
USING_SHARED_PTR(OR_Env_ItrAble);

#include "ClientPacketHandler.h"
#include "OnlineRPGGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#define SEND_PACKET(pkt)													\
	SendBufferRef sendBuffer = ClientPacketHandler::MakeSendBuffer(pkt);	\
	Cast<UOnlineRPGGameInstance>(GWorld->GetGameInstance())->SendPacket(sendBuffer);
