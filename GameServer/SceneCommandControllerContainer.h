#pragma once
#include "Command.h"
#include "ISceneCommandController.h"
#include "Logger.h"

using Command::COMMAND_GROUP_ID;

class SceneCommandControllerContainer
{
private:
    map<COMMAND_GROUP_ID, sptr<ISceneCommandController>> mapController;

public:
    SceneCommandControllerContainer(sptr<Logger> logger);
    sptr<ISceneCommandController> GetController(COMMAND_GROUP_ID packetGroupId);
};
