#pragma once
#include "Command.h"
#include "IGameSystemCommandController.h"
#include "Logger.h"

using Command::COMMAND_GROUP_ID;

class IGameSystemCommandController;

class GameSystemCommandControllerContainer
{
private:
    std::map<COMMAND_GROUP_ID, sptr<IGameSystemCommandController>> mapController;

public:
    GameSystemCommandControllerContainer(sptr<Logger> logger);
    sptr<IGameSystemCommandController> GetController(COMMAND_GROUP_ID packetGroupId);
};
