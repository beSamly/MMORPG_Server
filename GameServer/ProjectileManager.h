#pragma once
#include "TransformEntity.h"

class ProjectileManager
{
private:
	vector<sptr<TransformEntity>> vecProjectile;

public:
	ProjectileManager();
	void AddProjectile(sptr<TransformEntity> projectile) { vecProjectile.push_back(projectile); }
	vector<sptr<TransformEntity>> getAllProjectile() { return vecProjectile; };
};
