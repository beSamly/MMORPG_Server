#pragma once
#include "PhysicsEngine.h"

struct PatrolInfo
{
    int duration;
    int remainingDuration;
    PhysicsEngine::Vector3 direction;

    PatrolInfo() : duration(0), remainingDuration(0) {}
    PatrolInfo(int paramDuration, PhysicsEngine::Vector3 paramDirection) : duration(paramDuration), direction(paramDirection) {}
    bool isNull() { return duration == 0 && direction.IsNull() ? true : false; }
};

class PatrolController
{
private:
    queue<PatrolInfo> queuePatrolInfo;
    PatrolInfo currentPatrol;

public:
    PatrolController();
    void Update(float deltaTime);
    bool NeedToSwitchMoveDirection();
    void SwitchToNextMoveDirection();
    PhysicsEngine::Vector3 GetCurrentMoveDirection();
};
