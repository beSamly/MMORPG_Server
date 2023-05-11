#pragma once
#include "pch.h"
#include "Skill.h"
#include <PhysicsEngine.h>
#include "SkillInfo.h"

class SkillInfoManager
{
private:
	string FILE_PATH = "./json/SkillInfo.json";
	map<int, SkillInfo> mapSkillInfo;

public:
	SkillInfoManager() {};
	void LoadJsonData();
	SkillInfo GetSkillInfo(int skillIndex);

private:
	void LoadSkillInfo();
};
