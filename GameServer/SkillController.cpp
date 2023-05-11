#include "pch.h"
#include "SkillController.h"

void SkillController::Update(float deltaTime)
{
	if (!triggeredSkill.IsNull())
	{
		triggeredSkill.skill.Update(deltaTime);
	}
}

bool SkillController::IsUsingSkill() {
	return triggeredSkill.IsNull() ? false : true;
}

bool SkillController::HasSkill(int skillIndex) {
	return mapSkill.count(skillIndex) ? true : false;
}

void SkillController::AddSkill(Skill skill) { mapSkill[skill.skillIndex] = skill; }

void SkillController::UseSkill(int skillIndex, PlayerInput input)
{
	if (!triggeredSkill.IsNull())
	{
		// ERROR
		return;
	}

	if (!mapSkill.count(skillIndex))
	{
		// ERROR
		return;
	}

	triggeredSkill.skill = mapSkill[skillIndex];
	triggeredSkill.playerInput = input;
}

queue<TriggeredOperation> SkillController::GetReadyOperation()
{
	if (!triggeredSkill.IsNull())
	{
		return queue<TriggeredOperation>();
	}

	queue<Operation> operationQueue = triggeredSkill.skill.FlushReadyOperation();

	queue<TriggeredOperation> triggeredOperationQueue;
	while (!operationQueue.empty())
	{
		TriggeredOperation triggeredOperation;
		triggeredOperation.operation = operationQueue.front();
		triggeredOperation.playerInput = triggeredSkill.playerInput;
		triggeredOperationQueue.push(triggeredOperation);

		operationQueue.pop();
	}

	return triggeredOperationQueue;
}
