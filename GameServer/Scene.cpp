#include "pch.h"
#include "Scene.h"

Scene::Scene(string paramSceneName) : sceneName(paramSceneName)
{
	spawnManager = make_unique<SpawnManager>();
	npcManager = make_unique<NPCManager>();
	projectileManager = make_unique<ProjectileManager>();
}

void Scene::PushCommand(sptr<BaseReq> command)
{
	WRITE_LOCK;
	commandQueue.push(command);
}

queue<sptr<BaseReq>> Scene::FlushQueue()
{
	WRITE_LOCK;
	queue<sptr<BaseReq>> copied;
	std::swap(copied, commandQueue);
	return copied;
}
