#include "pch.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	mapScene = make_shared<map<string, sptr<Scene>>>();
	spawnManager = make_unique<SpawnManager>();
}

void SceneManager::AddScene(sptr<Scene> scene)
{
	mapScene->emplace(scene->sceneName, scene);
}

sptr<Scene> SceneManager::GetScene(string sceneName)
{
	map<string, sptr<Scene>>::iterator iter = mapScene->find(sceneName);

	if (iter != mapScene->end())
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}
