#pragma once
#include "pch.h"
#include <PhysicsEngine.h>
#include "SpawnInfo.h"
#include "JsonDataManager.h"

class SpawnInfoManager : public JsonDataManager
{
public:
	SpawnInfoManager() {};
	void LoadJsonData();
	SpawnInfo GetSpawnInfo(string sceneName);

private:
	map<string, SpawnInfo> mapSpawnInfo;
	void LoadDataFromPath() override;

protected:
	string GetFilePath() override { return "./json/SpawnInfo.json"; };

};
