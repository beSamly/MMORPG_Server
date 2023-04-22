#pragma once
#include "pch.h"
#include <PhysicsEngine.h>
#include "StatController.h"

class BaseStatManager
{
private:
    map<int, BaseStatInfo> mapBaseStatInfo;

public:
    BaseStatManager(){};
    BaseStatInfo GetBaseStat(int baseStatIndex);

    void LoadJsonData();

};
