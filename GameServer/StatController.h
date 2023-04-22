#pragma once
#include "StatModifier.h"
#include "BaseStatInfo.h"
#include "StatType.h"

namespace {
    const int MAX_STAT_TYPE = 8;
}

class StatController
{
private:
    vector<vector<StatModifier>> modifiers[MAX_STAT_TYPE];
    vector<vector<int>> cashedStat[MAX_STAT_TYPE];
    BaseStatInfo baseStat;

private:
    /*int currentHp;
    int currentMp;*/


public:
    /* Stat related */
    void SetBaseStat(BaseStatInfo paramBaseStat) { baseStat = paramBaseStat; }
    int GetBaseStat(STAT_TYPE statType);
public:
    StatController() {};
    void Update(float deltaTime);
};
