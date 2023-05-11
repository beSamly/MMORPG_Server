#pragma once
#include "pch.h"
#include "Skill.h"
#include <PhysicsEngine.h>
#include "SkillInfo.h"
#include "ProjectileInfo.h"

class ProjectileInfoManager
{
private:
	string FILE_PATH = "./json/ProjectileInfo.json";
	map<int, ProjectileInfo> mapProjectileInfo;

public:
	ProjectileInfoManager() {};
	void LoadJsonData();
	ProjectileInfo GetProjectileInfo(int index);
private:
	void LoadProjectileInfo();
};
