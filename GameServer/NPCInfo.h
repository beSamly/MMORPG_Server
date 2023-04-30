#pragma once
#include <string>

struct NPCInfo
{
    int npcIndex = 0;
    std::string npcName;
    int BaseStatIndex = 0;

    bool IsNull() { return npcIndex == 0 ? true : false; }
};
