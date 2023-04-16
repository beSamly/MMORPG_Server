#include "pch.h"
#include "Scene.h"

void Scene::PushCommand(sptr<CommandBase> command)
{
    WRITE_LOCK;
    commandQueue.push(command);
}

queue<sptr<CommandBase>> Scene::FlushQueue()
{
    WRITE_LOCK;
    queue<sptr<CommandBase>> copied(commandQueue);
    return copied;
}

void Scene::Update(float deltaTime) {}

sptr<Player> Scene::GetPlayer(int playerId)
{
    map<int, sptr<Player>>::iterator iter = mapPlayer.find(playerId);
    return iter != mapPlayer.end() ? iter->second : nullptr;
}