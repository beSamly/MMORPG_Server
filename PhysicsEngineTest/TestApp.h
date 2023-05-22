#pragma once
#include "NavigationMeshAgentManager.h"

using PhysicsEngine::Vector3;

class TestApp
{
private:
	uptr<NavigationMeshAgentManager> manager;
	sptr<PhysicsEngine::NavigationMeshAgent> navigationMeshAgent;

	Vector3 position;
	float radius;


public:
	TestApp();
	void Init();
	void Start();
	void DoResolveCollision();
	void TestInitIntManyTime();
	void TestInitVectorManyTime();
	void TestInitVector3ManyTime();

	void TestPhysicsEngineFunc();
};

