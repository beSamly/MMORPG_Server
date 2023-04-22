#pragma once
#include "Scene.h"

class SceneManager
{
private:
    USE_LOCK;
    sptr<map<string, sptr<Scene>>> mapScene;

public:
    SceneManager();
    void AddScene(sptr<Scene> scene);
    sptr<Scene> GetScene(string sceneName);
    sptr<map<string, sptr<Scene>>> GetAllScene() { return mapScene; }
};
