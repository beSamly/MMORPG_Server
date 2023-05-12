#pragma once
#include "pch.h"
#include "Skill.h"
#include <PhysicsEngine.h>
#include "SkillInfo.h"
#include "JsonDataManager.h"

class SkillInfoManager : public JsonDataManager
{
public:
	SkillInfoManager() {};
	void LoadJsonData();
	SkillInfo GetSkillInfo(int skillIndex);
private:
	map<int, SkillInfo> mapSkillInfo;
	void LoadDataFromPath() override;

protected:
	string GetFilePath() override { return "./json/SkillInfo.json"; };

};
