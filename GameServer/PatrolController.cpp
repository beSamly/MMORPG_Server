#include "pch.h"
#include "PatrolController.h"

using PhysicsEngine::Vector3;

PatrolController::PatrolController()
{
    //[TODO] 나중에 고도화
    Vector3 left_up = Vector3::UP() + Vector3::LEFT();
    left_up.Normalize();

    Vector3 right = Vector3::RIGHT();

    Vector3 left_down = Vector3::DOWN() + Vector3::LEFT();
    left_down.Normalize();

    queuePatrolInfo.push(PatrolInfo(4, left_up));
    queuePatrolInfo.push(PatrolInfo(4, right));
    queuePatrolInfo.push(PatrolInfo(4, left_down));
}

void PatrolController::Update(float deltaTime) {}

bool PatrolController::NeedToSwitchMoveDirection() { return currentPatrol.remainingDuration <= 0 ? true : false; }

void PatrolController::SwitchToNextMoveDirection()
{
    currentPatrol.remainingDuration = currentPatrol.duration;
    queuePatrolInfo.push(currentPatrol);

    currentPatrol = queuePatrolInfo.front();
    queuePatrolInfo.pop();
}

PhysicsEngine::Vector3 PatrolController::GetCurrentMoveDirection() { return currentPatrol.direction; }
