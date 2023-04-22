#include "pch.h"
#include <fstream>
#include "BaseStatManager.h"
#include "nlohmann/json.hpp"
#include "PhysicsEngine.h"

using json = nlohmann::json;

BaseStatInfo BaseStatManager::GetBaseStat(int baseStatIndex)
{
    if (mapBaseStatInfo.count(baseStatIndex))
    {
        return mapBaseStatInfo[baseStatIndex];
    }
    else
    {
        return BaseStatInfo();
    }
}

void BaseStatManager::LoadJsonData()
{
    std::ifstream f("./json/BaseStatInfo.json");

    json listStatInfo = json::parse(f);

    for (auto& jsonStatInfo : listStatInfo)
    {
        BaseStatInfo statInfo;
        statInfo.baseStatIndex = jsonStatInfo["BaseStatIndex"];
        statInfo.maxHp = jsonStatInfo["MaxHP"];
        statInfo.maxMp = jsonStatInfo["MaxMP"];
        statInfo.attackPower = jsonStatInfo["AttackPower"];
        statInfo.magicPower = jsonStatInfo["MagicPower"];
        statInfo.attackSpeed = jsonStatInfo["AttackSpeed"];
        statInfo.moveSpeed = jsonStatInfo["MoveSpeed"];
        statInfo.armor = jsonStatInfo["Armor"];
        statInfo.magicResistance = jsonStatInfo["MagicResistance"];

        mapBaseStatInfo[statInfo.baseStatIndex] = statInfo;
    }
}
