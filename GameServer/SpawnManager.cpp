#include "pch.h"
#include "SpawnManager.h"

SpawnManager::SpawnManager() { mapScene = make_shared<map<string, sptr<Scene>>>(); }


sptr<Scene> SpawnManager::GetScene(string sceneName)
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
