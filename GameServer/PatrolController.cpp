#include "pch.h"
#include "PatrolController.h"

using PhysicsEngine::Vector3;

PatrolController::PatrolController()
{
    //[TODO] 나중에 고도화
    Vector3 left_up = Vector3::UP() + Vector3::LEFT();
    left_up.Normalize();

    Vector3 right_up = Vector3::UP() + Vector3::RIGHT();
    right_up.Normalize();

    Vector3 right_down = Vector3::DOWN() + Vector3::RIGHT();
    right_down.Normalize();

    Vector3 left_down = Vector3::DOWN() + Vector3::LEFT();
    left_down.Normalize();

    /*queuePatrolInfo.push(PatrolInfo(4, Vector3::UP()));
    queuePatrolInfo.push(PatrolInfo(4, Vector3::DOWN()));*/

    //    queuePatrolInfo.push(PatrolInfo(4, Vector3::LEFT()));
    //  queuePatrolInfo.push(PatrolInfo(4, Vector3::RIGHT()));

    // 일단 4초씩 좌상, 우, 좌하 3방향으로 이동
    queuePatrolInfo.push(PatrolInfo(2.0f, left_up));
    queuePatrolInfo.push(PatrolInfo(2.0f, right_up));
    queuePatrolInfo.push(PatrolInfo(2.0f, right_down));
    queuePatrolInfo.push(PatrolInfo(2.0f, left_down));
}

void PatrolController::Update(float deltaTime) { 
    currentPatrol.remainingDuration -= deltaTime; 
}

bool PatrolController::NeedToSwitchMoveDirection() { return currentPatrol.remainingDuration <= 0 ? true : false; }

void PatrolController::SwitchToNextMoveDirection()
{
    currentPatrol.remainingDuration = currentPatrol.duration;
    queuePatrolInfo.push(currentPatrol);

    currentPatrol = queuePatrolInfo.front();
    queuePatrolInfo.pop();
}

PhysicsEngine::Vector3 PatrolController::GetCurrentMoveDirection() { return currentPatrol.direction; }
