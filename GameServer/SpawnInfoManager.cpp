#include "pch.h"
#include "SpawnInfoManager.h"

using namespace simdjson;

SpawnInfo SpawnInfoManager::GetSpawnInfo(string sceneName)
{
	auto iter = mapSpawnInfo.find(sceneName);

	if (iter != mapSpawnInfo.end())
	{
		return iter->second;
	}
	else
	{
		return SpawnInfo();
	}
}

void SpawnInfoManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const dom::element& jsonSceneSpawnInfo : data)
	{
		SpawnInfo spawnInfo;
		spawnInfo.sceneName = jsonSceneSpawnInfo["SceneName"].get_string().value();

		for (const dom::element& jsonNPCSpawnInfo : jsonSceneSpawnInfo["ListNPCSpawnInfo"])
		{
			NPCSpawnInfo npcSpawnInfo;
			npcSpawnInfo.npcIndex = jsonNPCSpawnInfo["NPCIndex"].get_int64();
			npcSpawnInfo.spawnCoolTime = jsonNPCSpawnInfo["SpawnCoolTime"].get_int64();
			npcSpawnInfo.totalNumber = jsonNPCSpawnInfo["TotalNumber"].get_int64();

			for (const dom::element& jsonSpawnPoint : jsonNPCSpawnInfo["ListSpawnPoint"])
			{
				PhysicsEngine::Vector3 vector;
				vector.x = jsonSpawnPoint["x"].get_double();
				vector.y = jsonSpawnPoint["y"].get_double();
				vector.z = jsonSpawnPoint["z"].get_double();

				npcSpawnInfo.vecSpawnPoint.push_back(vector);
			}

			spawnInfo.vecNPCSpawnInfo.push_back(npcSpawnInfo);
		}

		mapSpawnInfo[spawnInfo.sceneName] = spawnInfo;
	}
}
