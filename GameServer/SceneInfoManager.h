#pragma once
#include "pch.h"
#include <PhysicsEngine.h>

class SceneInfoManager
{
private:
    vector<SceneInfo> vecSceneInfo;

public:
    SceneInfoManager(){};
    void LoadJsonData();
    vector<SceneInfo> GetAllSceneInfo() { return vecSceneInfo; }
};
