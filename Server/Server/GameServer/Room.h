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
	// 싱글쓰레드 환경인마냥 코딩
	void Broadcast(SendBufferRef sendBuffer, uint64 exceptId = 0);

protected:
	// UpdateTick()에서 사용
	float _nowTickCount = 0.0f; // 현재 틱 카운트 (초 단위)
	float _beforeTickCount = 0.0f; // 이전 틱 카운트 (초 단위)
	int MAX_MONSTER_COUNT = 10; // 최대 몬스터 수
	atomic<int> _monsterCountAtomic = 0; // 현재 몬스터 수

private:
	unordered_map<uint64, ObjectRef> _objects;
	//unordered_map<uint64, PlayerRef> _players; // 플레이어 목록
	unordered_set<uint64> _players; // 플레이어 목록
	//unordered_map<uint64, MonsterRef> _monsters; // 몬스터 목록
	unordered_set<uint64> _monsters; // 몬스터 목록

	const float ROOM_MONSTER_SPAWN_DELAY = 2.0f; // 몬스터 스폰 딜레이 (초)
	float _spawnTimer = ROOM_MONSTER_SPAWN_DELAY; // 몬스터 스폰 타이머
	float _monsterCollisionRange = 50.0f; // 몬스터 간 충돌 범위 (단위: 미터)
};

extern RoomRef GRoom;