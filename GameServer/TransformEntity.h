#pragma once
#include <PhysicsEngine.h>

using PhysicsEngine::Vector3;

enum TransformEntityType : int
{
	TYPE_NONE = 0,
	TYPE_PLAYER,
	TYPE_NPC,
};

class TransformEntity
{
private:
	Vector3 position;
	Vector3 moveDirection;

public:
	TransformEntity() {};
	Vector3 GetPosition();
	void SetPosition(Vector3 newPositoin) { position = newPositoin; };
	void AddPosition(Vector3 addPositoin) { position += addPositoin; };
	void Update(float deltaTime);
	bool IsMoving();

	Vector3 GetMoveDirection();
	void SetMoveDirection(Vector3 direction);
	virtual TransformEntityType GetEntityType() abstract;
	virtual int GetEntityId() abstract;
};
