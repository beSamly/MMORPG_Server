#pragma once
#include "pch.h"
#include "NPCInfo.h"

class NPCInfoManager
{
private:
    map<int, NPCInfo> mapNPCInfo;

public:
    NPCInfoManager(){};
    void LoadJsonData();
    NPCInfo GetNPCInfo(int npxIndex);
};
