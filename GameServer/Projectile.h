#pragma once
#include "TransformEntity.h"

class Projectile : public TransformEntity
{
public:
	int projectileIndex;
	string projectileName;
	int projectileId;
	int speed;

public:
	Projectile();
	void Init();
	void Update(float deltaTime);
	virtual TransformEntityType GetEntityType() { return TransformEntityType::TYPE_PROJECTILE; };
	virtual int GetEntityId() { return projectileId; };

private:
	void UpdatePosition(float deltaTime);
};
