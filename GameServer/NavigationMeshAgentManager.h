#pragma once
#include "pch.h"
#include <PhysicsEngine.h>
#include "JsonDataManager.h"

class NavigationMeshAgentManager : public JsonDataManager
{
private:
	map<string, sptr<PhysicsEngine::NavigationMeshAgent>> mapNavigationMeshAgent;
	void LoadDataFromPath() override;

public:
	NavigationMeshAgentManager() {};
	sptr<PhysicsEngine::NavigationMeshAgent> GetNavigationMeshAgent(string sceneName);

private:
	void LoadSceneData();
protected:
	string GetFilePath() override { return "./json/NavigationMeshAgentData.json"; };

};
