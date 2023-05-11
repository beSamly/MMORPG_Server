#include "pch.h"
#include "SkillController.h"

void SkillController::Update(float deltaTime)
{
	if (!usingSkill.IsNull())
	{
		usingSkill.Update(deltaTime);
	}
}

bool SkillController::IsUsingSkill() {
	return usingSkill.IsNull() ? false : true;
}

bool SkillController::HasSkill(int skillIndex) {
	return mapSkill.count(skillIndex) ? true : false;
}

void SkillController::AddSkill(Skill skill) { mapSkill[skill.skillIndex] = skill; }

void SkillController::UseSkill(int skillIndex)
{
	if (!usingSkill.IsNull())
	{
		// ERROR
		return;
	}

	if (!mapSkill.count(skillIndex))
	{
		// ERROR
		return;
	}

	usingSkill = mapSkill[skillIndex];
}

queue<Operation> SkillController::GetReadyOperation()
{
	if (!usingSkill.IsNull())
	{
		return queue<Operation>();
	}

	return usingSkill.FlushReadyOperation();
}
