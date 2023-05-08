#pragma once
#include "pch.h"
#include "Skill.h"
#include <PhysicsEngine.h>

class SkillDataManager
{
private:
	string FILE_PATH = "./json/SkillData.json";
	map<int, Skill> mapSkillData;

public:
	SkillDataManager() {};
	void LoadJsonData();
	Skill GetSkillData(int skillIndex);
private:
	void LoadSkillData();
	void LoadExampleWithSimdjson();
};
