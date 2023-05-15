#pragma once
#include "pch.h"
#include "PhysicsEngine.h"

class NavigationMeshAgentManager
{
private:
	map<string, sptr<PhysicsEngine::NavigationMeshAgent>> mapNavigationMeshAgent;

public:
	NavigationMeshAgentManager() {};
	sptr<PhysicsEngine::NavigationMeshAgent> GetNavigationMeshAgent(string sceneName);
	void LoadDataFromPath();

protected:
	std::string GetFilePath() { return "../GameServer/json/NavigationMeshAgentData.json"; };

};
