#pragma once
#include "pch.h"
#include "NPCInfo.h"
#include "JsonDataManager.h"

class NPCInfoManager : public JsonDataManager
{
private:
	map<int, NPCInfo> mapNPCInfo;
	void LoadDataFromPath() override;

public:
	NPCInfoManager() {};
	void LoadJsonData();
	NPCInfo GetNPCInfo(int npxIndex);
protected:
	string GetFilePath() override { return "./json/NPCInfo.json"; };

};
