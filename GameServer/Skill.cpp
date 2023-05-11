#include "pch.h"
#include "Skill.h"

void Skill::Update(float deltaTime)
{
	float lastElapsed = elapsed;
	float currentElapsed = elapsed + deltaTime;

	for (int i = 0; i < vecOperation.size(); i++)
	{
		Operation& operation = vecOperation[i];
		int operationTime = vecOperationTime[i];

		if (lastElapsed <= operationTime && operationTime <= currentElapsed)
		{
			triggeredOperation.push(operation);
		}
	}
}

queue<Operation> Skill::FlushReadyOperation()
{
	queue<Operation> queue;
	std::swap(queue, triggeredOperation);
	return queue;
}
