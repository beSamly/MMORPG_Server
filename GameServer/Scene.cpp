#include "pch.h"
#include "Scene.h"

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

void Scene::Update(float deltaTime) {}
