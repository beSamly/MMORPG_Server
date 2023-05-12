#pragma once
#include "pch.h"
#include "Skill.h"
#include <PhysicsEngine.h>
#include "SkillInfo.h"
#include "ProjectileInfo.h"
#include "JsonDataManager.h"

class ProjectileInfoManager : public JsonDataManager
{
private:
	map<int, ProjectileInfo> mapProjectileInfo;

public:
	ProjectileInfoManager() {};
	ProjectileInfo GetProjectileInfo(int index);


protected:
	string GetFilePath() override { return "./json/ProjectileInfo.json"; };

private:
	void LoadDataFromPath() override;
};
