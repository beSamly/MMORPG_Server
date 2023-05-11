#pragma once
#include "Operation.h"
#include "PhysicsEngine.h"

class Skill
{
public:
	int skillIndex;
	string skillName;
	int coolTime;
	int duration;

private:
	vector<sptr<Operation>> vecOperation;
	vector<int> vecOperationTime;

public:
	Skill() : skillIndex(0), coolTime(0), duration(0), elapsed(0.0f) {}
	bool IsNull() { return skillIndex == 0; }
	void AddOperation(sptr<Operation>& operation) { vecOperation.push_back(operation); }
	void AddOperationTime(int operationTime) { vecOperationTime.push_back(operationTime); }
	void Update(float deltaTime);

	/* Non Static Data */

public:
	queue<sptr<Operation>> FlushReadyOperation();
private:
	float elapsed;
	queue<sptr<Operation>> triggeredOperation;
};

struct PlayerInput {
	PhysicsEngine::Vector3 direction;
};

struct TriggeredSkill {
	PlayerInput playerInput;
	Skill skill;

	bool IsNull() { return skill.IsNull(); }
};

struct TriggeredOperation
{
	PlayerInput playerInput;
	sptr<Operation> operation;
};