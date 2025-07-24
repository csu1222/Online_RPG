#include "pch.h"
#include "Creature.h"
#include "CreatureData.h"

Creature::Creature()
{
	objectInfo->set_object_type(Protocol::ObjectType::OBJECT_TYPE_CREATURE);
	creatureData = make_shared<CreatureData>(make_shared<Protocol::CreatureInfo>());
}

Creature::~Creature()
{
	creatureData.reset();
}

bool Creature::SetData(WCHAR* SetDataName, float SetDataValue)
{
    static const std::map<std::wstring, std::function<void(float)>> setterMap = {
        {L"Hp",     [this](float v) { creatureData->creatureInfo->set_hp(v); }},
        {L"MaxHp",  [this](float v) { creatureData->creatureInfo->set_max_hp(v); }},
        {L"Mp",     [this](float v) { creatureData->creatureInfo->set_mp(v); }},
        {L"MaxMp",  [this](float v) { creatureData->creatureInfo->set_max_hp(v); }},
        {L"Attack", [this](float v) { creatureData->creatureInfo->set_attack(v); }},
        {L"Defense",[this](float v) { creatureData->creatureInfo->set_defense(v); }},
        {L"Speed",  [this](float v) { creatureData->creatureInfo->set_speed(v); }},
        // 필요한 속성 계속 추가
    };

    if (SetDataName == nullptr || SetDataValue < 0.f)
        return false;

    auto it = setterMap.find(SetDataName);
    if (it != setterMap.end())
    {
        it->second(SetDataValue);
        return true;
    }
    return false;
}

float Creature::GetData(const WCHAR* GetDataName)
{
	float v = 0.f; // 기본값 설정, 필요에 따라 수정

    v = creatureData->creatureInfo->hp();
    static const std::map<std::wstring, std::function<float()>> getterMap =
    {
		{L"Id",     [this]() { return static_cast<float>(objectInfo->object_id()); }},
        {L"Hp",     [this]() { return creatureData->creatureInfo->hp(); }},
        {L"MaxHp",  [this]() { return creatureData->creatureInfo->max_hp(); }},
        {L"Mp",     [this]() { return creatureData->creatureInfo->mp(); }},
        {L"MaxMp",  [this]() { return creatureData->creatureInfo->max_hp(); }},
        {L"Attack", [this]() { return creatureData->creatureInfo->attack(); }},
        {L"Defense",[this]() { return creatureData->creatureInfo->defense(); }},
        {L"Speed",  [this]() { return creatureData->creatureInfo->speed(); }},
        // 필요한 속성 계속 추가
    };

    if (GetDataName == nullptr)
        return 0.f;

    auto it = getterMap.find(GetDataName);
    if (it != getterMap.end())
    {
        return it->second();
    }

    return 0.f;
}
