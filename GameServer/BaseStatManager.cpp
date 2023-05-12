#include "pch.h"
#include <fstream>
#include "BaseStatManager.h"
#include "nlohmann/json.hpp"
#include "PhysicsEngine.h"

using namespace simdjson;

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

void BaseStatManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const auto& jsonStatInfo : data)
	{
		BaseStatInfo statInfo;
		statInfo.baseStatIndex = jsonStatInfo["BaseStatIndex"].get_int64();
		statInfo.maxHp = jsonStatInfo["MaxHP"].get_int64();
		statInfo.maxMp = jsonStatInfo["MaxMP"].get_int64();
		statInfo.attackPower = jsonStatInfo["AttackPower"].get_int64();
		statInfo.magicPower = jsonStatInfo["MagicPower"].get_int64();
		statInfo.attackSpeed = jsonStatInfo["AttackSpeed"].get_int64();
		statInfo.moveSpeed = jsonStatInfo["MoveSpeed"].get_int64();
		statInfo.armor = jsonStatInfo["Armor"].get_int64();
		statInfo.magicResistance = jsonStatInfo["MagicResistance"].get_int64();

		mapBaseStatInfo[statInfo.baseStatIndex] = statInfo;
	}
}
