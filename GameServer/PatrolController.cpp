#include "pch.h"
#include "PatrolController.h"

using PhysicsEngine::Vector3;

PatrolController::PatrolController()
{
	//[TODO] ���߿� ��ȭ
	Vector3 left_up = Vector3::UP_LEFT();

	Vector3 right_up = Vector3::UP_RIGHT();

	Vector3 right_down = Vector3::DOWN_RIGHT();

	Vector3 left_down = Vector3::DOWN_LEFT();

	// �ϴ� 2�ʾ� 4�������� �̵�
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
