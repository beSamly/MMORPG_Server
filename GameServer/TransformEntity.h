#pragma once
#include <PhysicsEngine.h>

using PhysicsEngine::Vector3;

class TransformEntity
{
private:
	Vector3 position;
	Vector3 targetPosition;

public:
	TransformEntity() {};
	Vector3 GetPosition();
	void SetPosition(Vector3 newPositoin) { position = newPositoin; };
	void AddPosition(Vector3 addPositoin) { position += addPositoin; };
	Vector3 GetTargetPosition() { return targetPosition; };
	void SetTargetPosition(Vector3 p_position) { targetPosition = p_position; };
	void Update(float deltaTime);
	bool IsMoving();
};
