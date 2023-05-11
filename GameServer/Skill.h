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
	vector<Operation> vecOperation;
	vector<int> vecOperationTime;

public:
	Skill() : skillIndex(0), coolTime(0), duration(0), elapsed(0.0f) {}
	bool IsNull() { return skillIndex == 0; }
	void AddOperation(Operation& operation) { vecOperation.push_back(operation); }
	void Update(float deltaTime);

	/* Non Static Data */

public:
	queue<Operation> FlushReadyOperation();
private:
	float elapsed;
	queue<Operation> triggeredOperation;
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
	Operation operation;
};