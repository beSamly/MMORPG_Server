#include "pch.h"
#include <fstream>
#include "SpawnInfoManager.h"
#include <rapidjson/document.h>

using namespace rapidjson;

void SpawnInfoManager::LoadJsonData()
{
    // Open the file
    std::ifstream file("./json/SpawnInfo.json");

    // Read the entire file into a string
    string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Create a Document object
    // to hold the JSON data
    Document d;

    // Parse the JSON data
    d.Parse(jsonStr.c_str());

    // Check for parse errors
    if (d.HasParseError())
    {
        std::cerr << "Error parsing JSON: " << d.GetParseError() << std::endl;
        assert(false);
        return;
    }

    const auto& listSceneSpawnInfo = d.GetArray();

    for (auto& jsonSceneSpawnInfo : listSceneSpawnInfo)
    {
        SpawnInfo spawnInfo;

        spawnInfo.sceneName = jsonSceneSpawnInfo["SceneName"].GetString();
        const auto& jsonListNPCSpawnInfo = jsonSceneSpawnInfo["ListNPCSpawnInfo"].GetArray();

        for (auto& jsonNPCSpawnInfo : jsonListNPCSpawnInfo)
        {
            NPCSpawnInfo npcSpawnInfo;
            npcSpawnInfo.npcIndex = jsonNPCSpawnInfo["NPCIndex"].GetInt64();
            npcSpawnInfo.spawnCoolTime = jsonNPCSpawnInfo["SpawnCoolTime"].GetInt64();
            npcSpawnInfo.totalNumber = jsonNPCSpawnInfo["TotalNumber"].GetInt64();

            const auto& listSpawnPoint = jsonNPCSpawnInfo["ListSpawnPoint"].GetArray();
            for (auto& jsonSpawnPoint : listSpawnPoint)
            {
                PhysicsEngine::Vector3 vector;
                vector.x = jsonSpawnPoint["x"].GetFloat();
                vector.y = jsonSpawnPoint["y"].GetFloat();
                vector.z = jsonSpawnPoint["z"].GetFloat();

                npcSpawnInfo.vecSpawnPoint.push_back(vector);
            }

            spawnInfo.vecNPCSpawnInfo.push_back(npcSpawnInfo);
        }

        mapSpawnInfo[spawnInfo.sceneName] = spawnInfo;
    }
}

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
