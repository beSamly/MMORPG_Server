#pragma once
#include "pch.h"
#include <PhysicsEngine.h>
#include "SceneInfo.h"
#include "JsonDataManager.h"

class SceneInfoManager : public JsonDataManager
{

public:
	SceneInfoManager() {};
	void LoadJsonData();
	vector<SceneInfo> GetAllSceneInfo() { return vecSceneInfo; }

private:
	vector<SceneInfo> vecSceneInfo;
	void LoadDataFromPath() override;

protected:
	string GetFilePath() override { return "./json/SceneInfo.json"; };

};
