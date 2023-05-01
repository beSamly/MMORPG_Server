#pragma once
#include "TransformEntity.h"
#include "InputController.h"
#include "StatController.h"
#include "SkillController.h"
#include "PatrolController.h"

class NPC : public TransformEntity
{
public:
    int npcIndex;
    string npcName;
    int npcId;
    int spawnCoolTime;

    uptr<InputController> inputController;
    uptr<StatController> statController;
    uptr<SkillController> skillController;
    uptr<PatrolController> patrolController;
    PhysicsEngine::Vector3 spawnPoint;

public:
    NPC();
    void Init();
    int GetStat(STAT_TYPE statType);
    void Update(float deltaTime);
    virtual TransformaOwnerType GetEntityType() { return TransformaOwnerType::TYPE_NPC; };
    virtual int GetIdentifier() { return npcId; };

private:
    void UpdatePosition(float deltaTime);
    void UpdateMoveDirection(float deltaTime);
};
