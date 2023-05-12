#include "pch.h"
#include "NPCInfoManager.h"

NPCInfo NPCInfoManager::GetNPCInfo(int npxIndex)
{
	auto iter = mapNPCInfo.find(npxIndex);

	if (iter != mapNPCInfo.end())
	{
		return iter->second;
	}
	else
	{
		return NPCInfo();
	}
}

void NPCInfoManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const auto& jsonNPCInfo : data)
	{
		NPCInfo npcInfo;

		npcInfo.npcIndex = jsonNPCInfo["NPCIndex"].get_int64();
		npcInfo.npcName = jsonNPCInfo["NPCName"].get_string().value();
		npcInfo.BaseStatIndex = jsonNPCInfo["BaseStatIndex"].get_int64();

		mapNPCInfo[npcInfo.npcIndex] = npcInfo;
	}
}
