#include "pch.h"
#include "Scene.h"

Scene::Scene(string paramSceneName) : sceneName(paramSceneName)
{
	spawnManager = make_unique<SpawnManager>();
	npcManager = make_unique<NPCManager>();
	projectileManager = make_unique<ProjectileManager>();
}

void Scene::PushRequest(sptr<Request> packet)
{
	WRITE_LOCK;
	requestQueue.push(packet);
}

queue<sptr<Request>> Scene::FlushQueue()
{
	WRITE_LOCK;
	queue<sptr<Request>> copied;
	std::swap(copied, requestQueue);
	return copied;
}
