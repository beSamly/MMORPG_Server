#include"pch.h"
#include "TestApp.h"
#include <spdlog/spdlog.h>
#include "TimeUtil.h"
#include "PhysicsEngine.h"


using PhysicsEngine::Triangle;
using PhysicsEngine::CollisionTestUtil;

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


	TimeUtil::LogElapsedTimeInMilliSec("Calling numeric_limits<float>::min() 100000 time",
		[&]()->void {
			for (int i = 0; i < 100000; i++)
			{
				float test = (std::numeric_limits<float>::min)();
			}
		}
	);

	//TimeUtil::LogElapsedTime("Once", [&]()->void {
	//	Once();
	//	});

	/*
		0.016 sec 60프레임을 기준으로 1만번 돌려면
		DoResolveCollision 함수 1번 실행 시 0.0000016 sec  = 0.0016 ms 소요해야하는데
		현재는 0.013 ms 소요 -> 10배만 빨리지면 될 듯..
	*/

	TimeUtil::LogElapsedTime("Calling DoResolveCollision() 100000 time",
		[&]()->void {
			for (int i = 0; i < 100000; i++)
			{
				DoResolveCollision();
			}
		}
	);

	//TestPhysicsEngineFunc();
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

void TestApp::TestPhysicsEngineFunc()
{

	Vector3 a(423.026f, 111.655f, 142.275f);
	Vector3 b(418.557f, 111.342f, 143.776f);
	Vector3 c(421.719f, 111.125f, 144.219f);

	sptr<Triangle> triangle = make_shared<Triangle>(a, b, c);

	Vector3& first = triangle->vertices[0];
	Vector3& second = triangle->vertices[1];
	Vector3& third = triangle->vertices[2];

	int loop_time = 150000;

	TimeUtil::LogElapsedTime("Calling CheckCollision_BetweenTriangleSphere()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				CollisionTestUtil::CheckCollision_BetweenTriangleSphere(triangle, position, radius);
			}
		}
	);

	TimeUtil::LogElapsedTime("Calling FindSeperatingAxe_BetweenTriangleSphere()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				CollisionTestUtil::FindSeperatingAxe_BetweenTriangleSphere(triangle->vertices, position, radius);
			}
		}
	);

	TimeUtil::LogElapsedTime("Calling IsTargetLocatedOppositeSideFromTriangleNormal()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				Vector3 cp = triangle->GetCrossProduct();
				CollisionTestUtil::IsTargetLocatedOppositeSideFromTriangleNormal(cp, first, position);

			}
		}
	);

	TimeUtil::LogElapsedTime("Calling IsPointInTriangle()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				CollisionTestUtil::IsPointInTriangle(first, second, third, position);

			}
		}
	);

	TimeUtil::LogElapsedTime("Calling CalculateOverlap_BetweenPointSphere()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				Vector3 cp = triangle->GetCrossProduct();
				CollisionTestUtil::CalculateOverlap_BetweenPointSphere(cp, first, position, radius);

			}
		}
	);


	TimeUtil::LogElapsedTime("Calling IsSphereHangingOnLineOfTriangle()",
		[&]()->void {
			for (int i = 0; i < loop_time; i++)
			{
				CollisionTestUtil::IsSphereHangingOnLineOfTriangle(triangle, position, radius);

			}
		}
	);
}