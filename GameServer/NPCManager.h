#pragma once
#include "TransformEntity.h"

class NPCManager
{
private:
    vector<sptr<TransformEntity>> vecNPC;

public:
    NPCManager();
    void AddNPC(sptr<TransformEntity> npc) { vecNPC.push_back(npc); }
    vector<sptr<TransformEntity>> getAllNpc() { return vecNPC; };
};
