#pragma once
#include "pch.h"
#include "GameSystemReq.h"

class GameSystem;
class Scene;

using GameSystemReq::BaseReq;

class IGameSystemController
{
public:
    virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command) abstract;
};
