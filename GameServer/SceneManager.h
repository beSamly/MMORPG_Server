#pragma once
#include "Scene.h"

class SceneManager
{
private:
    sptr<map<string, sptr<Scene>>> mapScene;

public:
    SceneManager();
    bool AddScene(sptr<Scene> scene);
    sptr<Scene> GetScene(string sceneName);
    sptr<map<string, sptr<Scene>>> GetAllScene() { return mapScene; }
};
