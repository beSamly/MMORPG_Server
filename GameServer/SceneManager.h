#pragma once
#include "Scene.h"
#include "SpawnManager.h"

class SceneManager
{
private:
	USE_LOCK;
	sptr<map<string, sptr<Scene>>> mapScene;
	uptr<SpawnManager> spawnManager;

public:
	SceneManager();
	void AddScene(sptr<Scene> scene);
	sptr<Scene> GetScene(string sceneName);
	sptr<map<string, sptr<Scene>>> GetAllScene() { return mapScene; }
};
