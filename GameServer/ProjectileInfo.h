#pragma once
#include "pch.h"
#include <string>
#include "SkillInfo.h"

struct ProjectileInfo
{
	int projectileIndex;
	int maxRange;
	int speed;
	OperationInfo onCollisionOperation;
};
