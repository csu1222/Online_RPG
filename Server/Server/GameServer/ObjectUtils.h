#pragma once
#include "pch.h"

enum ObjectType : int64
{
	PLAYER = 0x1,  // 0001
	MONSTER = 0x2, // 0010
	// �߰� Ÿ���� ���⼭ ����
};

USING_SHARED_PTR(GameSession);
USING_SHARED_PTR(Player);
USING_SHARED_PTR(Monster);
USING_SHARED_PTR(Room);


class ObjectUtils
{
public:
    static int64 GenerateId(ObjectType type)
    {
        int64 uniqueId = s_IdGenerator.fetch_add(1); // ���� ID ����
        return (static_cast<int64>(type) << 60) | uniqueId; // ���� 4��Ʈ�� Ÿ�� ����
    }

    static ObjectType GetTypeFromId(int64 id)
    {
        return static_cast<ObjectType>((id >> 60) & 0xF); // ���� 4��Ʈ ����
    }

	static PlayerRef CreatePlayer(GameSessionRef session);

	static MonsterRef CreateMonster(RoomRef room);

private:
	static atomic<int64> s_IdGenerator;
};

