#include "pch.h"
#include "SceneManager.h"

SceneManager::SceneManager() { mapScene = make_shared<map<string, sptr<Scene>>>(); }

bool SceneManager::AddScene(sptr<Scene> scene)
{
    return true;
    if (mapScene->count(scene->sceneName))
    {
        return false;
    }

    mapScene->emplace(scene->sceneName, scene);
    return true;
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
