#include "pch.h"
#include "SceneInfoManager.h"
#include "PhysicsEngine.h"
#include "SceneInfo.h"

using namespace simdjson;

void SceneInfoManager::LoadDataFromPath() {

	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const auto& jsonSceneInfo : data)
	{
		SceneInfo sceneInfo;

		sceneInfo.sceneName = jsonSceneInfo["SceneName"].get_string().value();

		vecSceneInfo.push_back(sceneInfo);
	}
}


