#include"pch.h"
#include "TestApp.h"
#include <spdlog/spdlog.h>
#include "TimeUtil.h"

TestApp::TestApp()
{
	manager = make_unique<NavigationMeshAgentManager>();
}

void TestApp::Init()
{
	TimeUtil::LogElapsedTime("LoadJson", [&]()->void {
		manager->LoadDataFromPath();
		});

	navigationMeshAgent = manager->GetNavigationMeshAgent("Main");

	float x = 419.619f;
	float y = 113.919f;
	float z = 143.360f;
	position = Vector3(x, y, z);

	radius = 0.5f;
}

void TestApp::Start()
{
	if (navigationMeshAgent == nullptr) {
		spdlog::error("NavigationMeshAgentManger do not have manager for Main");
		return;
	}

	TimeUtil::LogElapsedTime("Init vector 100000 times", [&]()->void {
		TestInitVectorManyTime();
		});

	TimeUtil::LogElapsedTime("Init int 100000 times", [&]()->void {
		TestInitIntManyTime();
		});

	TimeUtil::LogElapsedTime("Init Vector3 100000 times", [&]()->void {
		TestInitVector3ManyTime();
		});

	//TimeUtil::LogElapsedTime("Once", [&]()->void {
	//	Once();
	//	});

	TimeUtil::LogElapsedTimeInMilliSec("Calling Once() 1000 times", [&]()->void {
		for (int i = 0; i < 1; i++) {
			TimeUtil::LogElapsedTimeInMilliSec("Once", [&]()->void {
				Once();
				});
		}
		});
}

void TestApp::Once()
{
	Vector3 newPosition = navigationMeshAgent->ResolveCollision(position, radius);
}

void TestApp::TestInitVectorManyTime()
{
	for (int i = 0; i < 100000; i++) {

		std::vector<int> temp;
	}
}

void TestApp::TestInitIntManyTime()
{
	for (int i = 0; i < 100000; i++) {

		int a = 10;
	}
}

void TestApp::TestInitVector3ManyTime()
{
	for (int i = 0; i < 100000; i++) {

		Vector3 test;
	}
}
