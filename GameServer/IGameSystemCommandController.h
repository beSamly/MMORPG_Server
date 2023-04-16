#pragma once
#include "pch.h"
#include "Command.h"
#include "GameSystem.h"

class GameSystem;
class CommandBase;

class IGameSystemCommandController
{
public:
    virtual int Process(GameSystem& gameSystem, sptr<CommandBase> command) abstract;
};
