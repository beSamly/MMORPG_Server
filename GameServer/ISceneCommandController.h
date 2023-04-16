#pragma once
#include "pch.h"
#include "Command.h"

class GameSystem;
class Scene;

using Command::CommandBase;

class ISceneCommandController
{
public:
    virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command) abstract;
};
