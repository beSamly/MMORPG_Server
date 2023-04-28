#include "pch.h"
#include "SpawnManager.h"

SpawnManager::SpawnManager() { mapScene = make_shared<map<string, sptr<Scene>>>(); }

void SpawnManager::Update(float deltaTime) {}

