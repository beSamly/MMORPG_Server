#include "pch.h"
#include "StatController.h"

int StatController::GetBaseStat(STAT_TYPE statType)
{
    switch (statType)
    {
        case STAT_TYPE::MAX_HP:
            return baseStat.maxHp;
        case STAT_TYPE::MAX_MP:
            return baseStat.maxMp;
        case STAT_TYPE::ATTACK_POWER:
            return baseStat.attackPower;
        case STAT_TYPE::MAGIC_POWER:
            return baseStat.magicPower;
        case STAT_TYPE::ATTACK_SPEED:
            return baseStat.attackSpeed;
        case STAT_TYPE::MOVE_SPEED:
            return baseStat.moveSpeed;
        case STAT_TYPE::ARMOR:
            return baseStat.armor;
        case STAT_TYPE::MAGIC_RESISTANCE:
            return baseStat.magicResistance;
    }
}

void StatController::Update(float deltaTime) {}
