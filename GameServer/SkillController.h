#pragma once
#include "Skill.h"
#include "PhysicsEngine.h"

class SkillController
{
private:
	TriggeredSkill triggeredSkill;

public:
	SkillController() {};
	void Update(float deltaTime);
	bool IsUsingSkill();
	bool HasSkill(int skillIndex);

public:
	/* 데이터 세팅 */
	void AddSkill(Skill skill);
	void UseSkill(int skillIndex, PlayerInput input);
	queue<TriggeredOperation> GetReadyOperation();

private:
	map<int, Skill> mapSkill;
	//vector<SkillData> baseAttack;
	//vector<SkillData> skills;
};
