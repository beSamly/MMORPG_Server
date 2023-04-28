#pragma once
#include "Scene.h"

class SpawnInfo
{
	int monsterIndex;
};

class SpawnManager
{
private:
	USE_LOCK;
	sptr<map<string, sptr<Scene>>> mapScene;

public:
	SpawnManager();
	void Update(float deltaTime);


};
