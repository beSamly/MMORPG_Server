#include "pch.h"
#include <fstream>
#include "SceneInfoManager.h"
#include "nlohmann/json.hpp"
#include "PhysicsEngine.h"
#include "SceneInfo.h"

using json = nlohmann::json;

void SceneInfoManager::LoadJsonData() { 
 std::ifstream f("./json/SceneInfo.json");

    json listSceneInfo = json::parse(f);

    for (auto& jsonSceneInfo : listSceneInfo)
    {
        SceneInfo sceneInfo;

        sceneInfo.sceneName = jsonSceneInfo["sceneName"];

        vecSceneInfo.push_back(sceneInfo);
    }
}

