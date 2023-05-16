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

	TimeUtil::LogElapsedTimeInMilliSec("Init vector 100000 times", [&]()->void {
		TestInitVectorManyTime();
		});

	TimeUtil::LogElapsedTimeInMilliSec("Init int 100000 times", [&]()->void {
		TestInitIntManyTime();
		});

	TimeUtil::LogElapsedTimeInMilliSec("Init Vector3 100000 times", [&]()->void {
		TestInitVector3ManyTime();
		});

	//TimeUtil::LogElapsedTime("Once", [&]()->void {
	//	Once();
	//	});

	/*
		0.016 sec 60�������� �������� 1���� ������
		DoResolveCollision �Լ� 1�� ���� �� 0.0000016 sec  = 0.0016 ms �ҿ��ؾ��ϴµ�
		����� 0.013 ms �ҿ� -> 10�踸 �������� �� ��..
	*/
	// 5õ object ���� 30�������� ���µ� �ɸ��� �ð�... 2��... ���� ����
	TimeUtil::LogElapsedTime("Calling DoResolveCollision() 10000 time",
		[&]()->void {
			for (int j = 0; j < 30; j++)
			{
				for (int i = 0; i < 5000; i++)
				{
					DoResolveCollision();
				}
			}
		}
	);
}

void TestApp::DoResolveCollision()
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
