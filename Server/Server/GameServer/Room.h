#pragma once
#include "JobQueue.h"

class Room : public JobQueue
{
public:
	Room();
	virtual ~Room();

public:
	bool EnterRoom(ObjectRef object, bool randPos = true);
	bool LeaveRoom(ObjectRef object);

	bool HandleEnterPlayer(PlayerRef player);
	bool HandleLeavePlayer(PlayerRef player);
	void HandleMove(Protocol::C_MOVE pkt);

	bool HandleSpawnMonster(MonsterRef monster);
	bool HandleDespawnMonster(MonsterRef monster);

public:
	void UpdateTick();
	void UpdateSpawnMonser(float deltaTime);
	RoomRef GetRoomRef();

private:
	bool AddObject(ObjectRef object);
	bool RemoveObject(uint64 objectId);

	void SetRandomPosition(ObjectRef object);

	bool BroadcastToEnteredPlayers(ObjectRef object, bool add_result);
	bool BroadcastToSpawnedMonsters();

private:
	bool CheckMonsterCount();
	bool CheckMonsterCollision(MonsterRef monster);

public:
	// �̱۾����� ȯ���θ��� �ڵ�
	void Broadcast(SendBufferRef sendBuffer, uint64 exceptId = 0);

protected:
	// UpdateTick()���� ���
	float _nowTickCount = 0.0f; // ���� ƽ ī��Ʈ (�� ����)
	float _beforeTickCount = 0.0f; // ���� ƽ ī��Ʈ (�� ����)
	int MAX_MONSTER_COUNT = 10; // �ִ� ���� ��
	atomic<int> _monsterCountAtomic = 0; // ���� ���� ��

private:
	unordered_map<uint64, ObjectRef> _objects;
	//unordered_map<uint64, PlayerRef> _players; // �÷��̾� ���
	unordered_set<uint64> _players; // �÷��̾� ���
	//unordered_map<uint64, MonsterRef> _monsters; // ���� ���
	unordered_set<uint64> _monsters; // ���� ���

	const float ROOM_MONSTER_SPAWN_DELAY = 2.0f; // ���� ���� ������ (��)
	float _spawnTimer = ROOM_MONSTER_SPAWN_DELAY; // ���� ���� Ÿ�̸�
	float _monsterCollisionRange = 50.0f; // ���� �� �浹 ���� (����: ����)
};

extern RoomRef GRoom;