#pragma once
#include "pch.h"
#include "PhysicsEngine.h"
#include "StatController.h"
#include "JsonDataManager.h"

class BaseStatManager : public JsonDataManager
{
private:
	map<int, BaseStatInfo> mapBaseStatInfo;
	void LoadDataFromPath() override;

public:
	BaseStatManager() {};
	BaseStatInfo GetBaseStat(int baseStatIndex);

	void LoadJsonData();

protected:
	string GetFilePath() override { return "./json/BaseStatInfo.json"; };

};
