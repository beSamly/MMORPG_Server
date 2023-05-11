#pragma once
#include "Skill.h"

class SkillController
{
private:
	Skill usingSkill;

public:
	SkillController() {};
	void Update(float deltaTime);
	bool IsUsingSkill();
	bool HasSkill(int skillIndex);

public:
	/* ������ ���� */
	void AddSkill(Skill skill);
	void UseSkill(int skillIndex);
	queue<Operation> GetReadyOperation();

private:
	map<int, Skill> mapSkill;
	//vector<SkillData> baseAttack;
	//vector<SkillData> skills;
};
