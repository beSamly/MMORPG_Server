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
			operationReady.push(operation);
		}
	}
}

queue<Operation> Skill::GetOperationReady()
{
	queue<Operation> queue;
	std::swap(queue, operationReady);
	return queue;
}
