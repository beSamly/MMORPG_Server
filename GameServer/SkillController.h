#pragma once
#include "ChampRelatedStruct.h"
#include "Skill.h"

class SkillController
{
private:
	Skill usingSkill;

public:
	SkillController() {};
	void Update(float deltaTime);
	bool IsUsingSkill();
	bool CanUseSkill();

public:
	/* 데이터 세팅 */
	void AddSkill(Skill skill);
	void UseSkill(int skillIndex);
private:
	map<int, Skill> mapSkill;
	vector<SkillData> baseAttack;
	vector<SkillData> skills;
};
