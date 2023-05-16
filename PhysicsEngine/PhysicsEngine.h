#pragma once
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;
template <typename T>
using sptr = std::shared_ptr<T>;

namespace PhysicsEngine
{
	const float PI = 3.1415926535897931;
	const float Deg2Rad = PI / 180.0f;
	const float FLOAT_MIN = (std::numeric_limits<float>::min)();
	const float FLOAT_MAX = (std::numeric_limits<float>::max)();
	const float EPSILON = std::numeric_limits<float>::epsilon();

	class Vector3
	{
	public:
		float x;
		float y;
		float z;

	public:
		Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(float pX, float pY, float pZ) : x(pX), y(pY), z(pZ) {}

		void Normalize()
		{
			// t len = std::sqrt(x * x + y * y + z * z);
			float len = sqrtf(x * x + y * y + z * z);
			if (len != 0.0f)
			{
				x /= len;
				y /= len;
				z /= len;
			}
		}

		bool IsNull() { return x == 0.0f && y == 0.0f && z == 0.0f ? true : false; }

	public:
		Vector3 operator-(Vector3 rhs) { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }

		void operator+=(Vector3 rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
		}

		void operator-=(Vector3 rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
		}

		Vector3 operator+(Vector3 rhs) { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
		Vector3 operator*(float value) { return Vector3(x * value, y * value, z * value); }

		bool operator==(Vector3 rhs) { return x == rhs.x && y == rhs.y && z == rhs.z; }

		float Magnitude() { return std::sqrt(x * x + y * y + z * z); }

		static float DotProduct(Vector3 a, Vector3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

		static Vector3 CrossProduct(Vector3 a, Vector3 b)
		{
			float cx = a.y * b.z - a.z * b.y;
			float cy = a.z * b.x - a.x * b.z;
			float cz = a.x * b.y - a.y * b.x;

			return Vector3(cx, cy, cz);
		}

		static float Distance(Vector3 a, Vector3 b)
		{
			float num = a.x - b.x;
			float num2 = a.y - b.y;
			float num3 = a.z - b.z;
			return sqrtf(num * num + num2 * num2 + num3 * num3);
		}

		static Vector3 Project(Vector3& vector, Vector3& onNormal)
		{
			float num = DotProduct(onNormal, onNormal);
			{
				return Vector3(0.0f, 0.0f, 0.0f);
			}

			float num2 = DotProduct(vector, onNormal);
			return Vector3(onNormal.x * num2 / num, onNormal.y * num2 / num, onNormal.z * num2 / num);
		}

		static Vector3 UP() { return Vector3(0.0f, 0.0f, 1.0f); }
		static Vector3 DOWN() { return Vector3(0.0f, 0.0f, -1.0f); }
		static Vector3 LEFT() { return Vector3(-1.0f, 0.0f, 0.0f); }
		static Vector3 RIGHT() { return Vector3(1.0f, 0.0f, 0.0f); }
	};

	class Triangle
	{
	public:
		string name;
		vector<Vector3> vertices;
		Vector3 crossProduct;
		Vector3 centroid;

		Triangle(Vector3 a, Vector3 b, Vector3 c)
		{
			vertices.push_back(a);
			vertices.push_back(b);
			vertices.push_back(c);
			CalculateCrossProduct();
			CalculateCentroid();
		}

		Triangle() {};

		Vector3 GetCrossProduct() { return crossProduct; }
		Vector3 GetCentroid() { return centroid; }

	private:
		void CalculateCrossProduct()
		{
			Vector3 a = vertices[0] - vertices[1];
			Vector3 b = vertices[1] - vertices[2];

			crossProduct = Vector3::CrossProduct(a, b);
			crossProduct.Normalize();
		}

		void CalculateCentroid()
		{
			Vector3 temp = vertices[0] + vertices[1] + vertices[2];
			temp.x /= 3;
			temp.y /= 3;
			temp.z /= 3;

			centroid = temp;
		}
	};

	class AdjacentMeshInfo
	{
	public:
		string meshName;
		vector<int> adjacentTriangleIndices;
	};

	class Mesh
	{
	public:
		string name;
		vector<sptr<Triangle>> vecTriangle;
		void AddTriangle(sptr<Triangle> triangle) { vecTriangle.push_back(triangle); }
	};

	class GridInfo
	{
	public:
		string gridIndex;
		vector<AdjacentMeshInfo> vecAdjacentMeshInfo;
	};

	class CollisionInfo
	{
	public:
		CollisionInfo() {};

		// HISTORY - 아래 두 필드는 Unity에서 테스트 위해서 생성한 필드로 퍼포먼스 저하를 유발할 수 있다
		//string fromMeshName;
		//sptr<Triangle> fromTriangle;
		Vector3 penetrationNormal;
		float penetrationDepth = 0.0f;

		bool IsCollided() { return penetrationDepth != 0.0f; }
	};

	enum DotProductType : int
	{
		SAME_DIRACTION = 1,
		OPPOSITE_DIRECTION = -1,
		PERPENDICULAR = 0,
		NONE = -2,
	};

	class CollisionTestUtil
	{
	public:
		static DotProductType GetDotProductTypeBetween(Vector3 a, Vector3 b)
		{
			float value = Vector3::DotProduct(a, b);

			// if (value == 0.0f) 로 비교하게 되면 0.00001f 같은 경우 거의
			// perendicular이지만 조건부에 타지 않으니 0.0f 보다는 크도 0.001f 보다 작은
			// 경우는 perendicular 로 간주한다
			if (0.0f < value && value < 0.001f)
			{
				return DotProductType::PERPENDICULAR;
			}
			else if (value < 0.0f)
			{
				return DotProductType::OPPOSITE_DIRECTION;
			}
			else if (value > 0.0f)
			{
				return DotProductType::SAME_DIRACTION;
			}

			return DotProductType::NONE;
		}

		static CollisionInfo CheckCollision_BetweenTriangleSphere(sptr<Triangle>& triangle, Vector3& target, float radius)
		{
			static CollisionInfo defaultCollisionInfo;

			Vector3& first = triangle->vertices[0];
			Vector3& second = triangle->vertices[1];
			Vector3& third = triangle->vertices[2];

			/*----------------------------------------------------------------------------------------
							아래 함수 호출을 주석친 이유는 굳이 Seperating Axe 검사를 하지
			않아도 CalculateOverlap_BetweenPointSphere, IsSphereHangingOnLineOfTriangle
			함수에서 걸러진다. 혹시 나중에 제대로 작동 안 하면 주석 풀기 History : 가끔
			Unity prefab에 이상한 vertex a,b,c 가 한 라인에 있는 mesh가 딸려올 때가
			있다. 이경우 seperating axe 검사를 해주면 일단 걸러진다..
			------------------------------------------------------------------------------------------*/
			// 확실한 Seperating Axe 찾았으면 충돌 검사할 필요가 없이 충돌하지 않은
			// 상태이다.
			if (FindSeperatingAxe_BetweenTriangleSphere(triangle->vertices, target, radius))
			{
				return defaultCollisionInfo;
			}

			//역방향 충돌 모두 제거 - 벽 같은 경우는 플레이어가 벽을 뚫고 지나가려고
			//하면 역방향 충돌이 발생해서 벽 건너편으로 순간이동 현상 발생
			// History - Terrain이 엄청 촘촘하고 울퉁불퉁한 경우에는 플레이어가 방향키
			// 이동을 했을 때 Normal의 반대방향으로 가서 땅이 뚫고 내려갈 수 있어서 주석
			// 처리.
			Vector3 cp = triangle->GetCrossProduct();
			if (IsTargetLocatedOppositeSideFromTriangleNormal(cp, first, target))
			{
				return defaultCollisionInfo;
			}

			if (IsPointInTriangle(first, second, third, target))
			{
				Vector3 cp = triangle->GetCrossProduct();
				float overlap = CalculateOverlap_BetweenPointSphere(cp, first, target, radius);
				if (overlap > 0.0f)
				{
					CollisionInfo collisionInfo;
					collisionInfo.penetrationDepth = overlap;
					collisionInfo.penetrationNormal = triangle->GetCrossProduct();
					return collisionInfo;
				}
			}
			else
			{
				// Sphere가 라인에 걸쳐있는 경우에는 sphere.radius - line 까지의 거리가
				// penetraion depth가 되어야 한다.
				{
					float overlap = IsSphereHangingOnLineOfTriangle(triangle, target, radius);
					if (overlap > 0.0f)
					{
						CollisionInfo collisionInfo;
						collisionInfo.penetrationDepth = overlap;
						collisionInfo.penetrationNormal = triangle->GetCrossProduct();
						return collisionInfo;
					}
				}
			}

			// 충돌 안 한 경우
			return defaultCollisionInfo;
		}

		static bool IsCollidedFromSlope(CollisionInfo& collisionInfo)
		{
			if (abs(collisionInfo.penetrationNormal.y) > 0.01f && (abs(collisionInfo.penetrationNormal.x) > 0.001f || abs(collisionInfo.penetrationNormal.z) > 0.001f))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		static CollisionInfo ResolveSlope(CollisionInfo& collisionInfo)
		{
			// 물체가 지형과 충돌해서 발생한 Normal 중 ↖ 와 ↗ 는 경사로에서 발생하는
			// 충돌이니 미끄럼 방지를 위해 따로 별도 처리 해준다 ↙ 하고 ↘ 방향 충돌은
			// 점프를 해서 어딘가 부딪혔을 때이기 때문에 y > 0.0f 로 기준을 잡았다
			// HISTORY - 0.01f를 적용해준 건 아주 미세한 slope은 무시하기 위함
			if (IsCollidedFromSlope(collisionInfo))
			{
				Vector3 penetraionNormal = collisionInfo.penetrationNormal;

				// new Vector3(0f, 1f, 0f)로 해도 되고 new Vector3(0f, temp.y, 0f) 로 해도
				// 같은 값이 나와야한다

				// float angle = Vector3::AngleBetween(new Vector3(0.0f, 1.0f, 0.0f), new
				// Vector3(penetraionNormal.x, penetraionNormal.y, penetraionNormal.z));
				// // In c# float angle = atan2(diff.x, diff.y, diff.z); // In c++
				Vector3 upVector = Vector3(0.0f, 1.0f, 0.0f);
				float angleInDegree = std::acos(Vector3::DotProduct(upVector, penetraionNormal) / (upVector.Magnitude()) * penetraionNormal.Magnitude());

				// float angleInDegree = angle * 180 / PI;
				float anotherAngleInDegree = 90.0f - angleInDegree;

				// 삼각비의 법칙 => a / sin(반대편 각) = b / sin(반대편 각) = c / sin
				// (반대편 각) (빗변 c 의 길이 / Sin(90)) == (penetrationDepth /
				// sin(반대편 각)) Sin(90)은 항상 1이니 최종 공식은 => 빗변 c 의 길이 ==
				// penetrationDepth / sin(반대편 각) float 빗변의 길이 =
				// (collisionInfo.penetrationDepth / sin(anotherAngleInDegree)); sin()
				// 함수는 degree가 아닌 radian을 인자로 받으므로 Mathf.Deg2Rad 를
				// 곱해준다.
				float divider = sin(anotherAngleInDegree * Deg2Rad);
				float newDepth = (collisionInfo.penetrationDepth / divider); // Sin(90도)는 무조건 1이니 생략

				CollisionInfo resolved;
				resolved.penetrationDepth = abs(newDepth);
				resolved.penetrationNormal = Vector3(0.0f, 1.0f, 0.0f);
				/*resolved.fromMeshName = collisionInfo.fromMeshName;
				resolved.fromTriangle = collisionInfo.fromTriangle;*/

				// 어떻게 빗변의 크기보다 클 수 있지...?
				// newDepth 는 빗변의 길이이므로 삼각형의 그 어떠한 line의 길이도 빗변보다
				// 클 수가 없다.
				if (collisionInfo.penetrationDepth > newDepth)
				{
					//!!MATHMETICAL ERROR!!!
				}

				return resolved;
			}

			return collisionInfo;
		}

		// Vector3 A와 B 를 projectTo(normal) 기준으로 overlap 계산을 하는데 정방향
		// overlap인지 체크 normal -> A B가 정방향(forward) normal -> B A는
		// 역방향(backward)
		static float CalculateOverlap_BetweenPointSphere(Vector3& projectTo, Vector3& targetA, Vector3& targetB, float radius)
		{
			// 설명
			// crossProduct와 target 사이의 거리를 구한다
			// crossProduct와 vertex 사이의 거리를 구한다(cross product 과 vertex[0, 1,
			// 2] 사이의 Dot product 는 모두 동일)
			float distanceToTargetA = Vector3::DotProduct(projectTo, targetA);
			float distanceToTargetB = Vector3::DotProduct(projectTo, targetB);

			// 둘 사이의 거리가 Sphere.radius 사이의 거리보다 작으면 충돌한 상태!
			float distanceBetween = abs(distanceToTargetA - distanceToTargetB);

			// 거리가 radius 보다 큰 경우 Overlap이 없다
			if (radius < distanceBetween)
			{
				return 0.0f;
			}

			return radius - distanceBetween;
		}

	public:
		static bool IsTargetLocatedOppositeSideFromTriangleNormal(Vector3& normal, Vector3& targetA, Vector3& targetB)
		{
			float distanceToTargetA = Vector3::DotProduct(normal, targetA);
			float distanceToTargetB = Vector3::DotProduct(normal, targetB);

			return distanceToTargetB < distanceToTargetA ? true : false;
		}

		static float IsSphereHangingOnLineOfTriangle(sptr<Triangle>& t, Vector3& target, float radius)
		{
			int totalCount = t->vertices.size();

			for (int i = 0; i < 3; i++)
			{
				Vector3& A = t->vertices[i];
				Vector3& B = t->vertices[(i + 1) % totalCount];
				Vector3 normal = B - A; // vertex a => vertex b 까지의 방향 normal

				// Normal 을 구할 때 - vertices[i] 해줬으니 Target 도 - vertices[i]
				// 해줘야하고 Perpendicular 구한 뒤 + vertices[i] 해줘야한다.
				{
					Vector3 newTarget = target - A;
					Vector3 perpendicular = Vector3::Project(newTarget, normal);
					Vector3 newPern = perpendicular + A;

					float A_Dot = Vector3::DotProduct(normal, A);
					float B_Dot = Vector3::DotProduct(normal, B);
					float pernDot = Vector3::DotProduct(normal, newPern);

					// History - B_Dot = 0.98468, pernDot = 0.98455 일 때 에디터 상 충돌을
					// 한 것 처럼 보이는데 B_Dot < pernDot 연산에 의해서 return 0f가 되고
					// 있어서 float decial의 3번째 자리까지 같은 경우는 같은 값으로 간주
					// A_Dot = (float)System.Math.Round(A_Dot, 3);
					// B_Dot = (float)System.Math.Round(B_Dot, 3);
					// pernDot = (float)System.Math.Round(pernDot, 3);

					// 90도를 이루는 지점 pernDot이 A와 B 라인 사이에 없을 경우
					if (pernDot < A_Dot || B_Dot < pernDot)
					{
						continue;
					}

					float distance = Vector3::Distance(newPern, target);
					if (distance < radius && (radius - distance) > 0.0001f)
					{
						return radius - distance;
					}
				}
			}

			return 0.0f;
		}

		static bool IsPointInTriangle(Vector3& A, Vector3& B, Vector3& C, Vector3& P)
		{
			// 방향 백터 [A-B, B-C, C-A]와 방향 백터[A-P, B-P, C-P] 가 같은 방향을
			// 가르키는지 체크 모든 방향 백터가 같은 방향을 가르킨다면 점 P는 Triangle
			// 안에 있다
			if (SameSide(P, A, B, C) && SameSide(P, B, A, C) && SameSide(P, C, A, B))
			{
				return true;
			}

			// 다른 방향이 하나라도 있으면 Vector P는 Triangle 안에 있지 않다
			return false;
		}

		// 두 방향 백터가 같은 방향을 가르키는지 체크
		static bool SameSide(Vector3& p1, Vector3& p2, Vector3& A, Vector3& B)
		{
			Vector3 cp1 = Vector3::CrossProduct(B - A, p1 - A); // 방향 백터 1
			Vector3 cp2 = Vector3::CrossProduct(B - A, p2 - A); // 방향 백터 2

			// 방향 백터 1과 2의 Dot product가 0 이상이면 같은 방향
			if (Vector3::DotProduct(cp1, cp2) >= 0.0f)
			{
				return true;
			}

			// 음수이면 다른 방향
			return false;
		}

		static bool FindSeperatingAxe_BetweenTriangleSphere(vector<Vector3>& vertices, Vector3& target, float radius)
		{
			for (int i = 0; i < 3; i++)
			{
				Vector3 normal = target - vertices[i];
				normal.Normalize();

				float max = (std::numeric_limits<float>::min)();
				float min = (std::numeric_limits<float>::max)();
				float targetDotProduct = Vector3::DotProduct(normal, target);

				for (int j = 0; j < 3; j++)
				{
					float dotProduct = Vector3::DotProduct(normal, vertices[j]);

					if (dotProduct > max)
					{
						max = dotProduct;
					}

					if (dotProduct < min)
					{
						min = dotProduct;
					}
				}

				if (min > (targetDotProduct + radius) || max < (targetDotProduct - radius))
				{
					return true;
				}
			}

			return false;
		}
	};

	class NavigationMeshAgent
	{
	private:
		int GRID_SIZE;

	public:
		string sceneName;
		map<string, sptr<Mesh>> mapMesh;
		map<string, sptr<GridInfo>> mapGridInfo;

		void SetGridSize(int gridSize) { GRID_SIZE = gridSize; }

		// !!DEPRECATED!!
		void AddTriangle(string meshName, sptr<Triangle> triangle) { mapMesh[meshName]->AddTriangle(triangle); }

		void AddGridInfo(sptr<GridInfo> gridInfo) { mapGridInfo[gridInfo->gridIndex] = gridInfo; }

		void AddMesh(sptr<Mesh> mesh)
		{
			if (mapMesh.count(mesh->name))
			{
				//!!ERROR
			}

			mapMesh[mesh->name] = mesh;
		}

		// Version 2 - 위치를 기반으로 GridIndex를 알아내고 해당 Grid에 인접한 다른
		// Grid 들에 속하는 Mesh 중 인접한 Triangle 들만 체크한다. Dependency 1 -
		// GetBestCollisionInfo_From_Terrain : 충돌한 정보 중 가장 정확한 정보만 처리
		// Dependency 2 - GetBestCollisionInfo_From_Object : 충돌한 정보 중
		// DotProductType 별로 가장 정확한 정보들만 처리
		Vector3 ResolveCollision(Vector3 position, float radius, bool ignoreSlope = true)
		{
			// HISTORY - map에서 Terrain 데이터가 있는지 없는지는 서버 구동 시 혹은 json 데이터 읽은 후 체크하도록.
			// ResolveCollision 함수 내에서는 프레임 확보를 위해 최대한 적은 일을 해야한다.
			/*if (!mapMesh.count("Terrain"))
			{
				return position;
			}*/

			int row = (int)(position.z / GRID_SIZE);
			int column = (int)(position.x / GRID_SIZE);
			// string gridIndex = std::to_string(row) + "_" + std::to_string(column); // 이 함수 퍼포먼스가 너무 안 좋아서 일단 static string gridIndex로 대체하고 물리엔진 성능 테스트 하자
			static string gridIndex = "47_140";

			auto iter = mapGridInfo.find(gridIndex); // mapGridInfo에 2만 개의 데이터가 있어서 느린듯... 일단 static으로 대체해놓고 나머지 성능 테스트
			//static auto iter = mapGridInfo.find(gridIndex);
			if (iter == mapGridInfo.end())
			{
				std::cout << "[PhysicsEngine] gridIndex not found - " << gridIndex << std::endl;
				return position;
			}

			static vector<CollisionInfo> vecTotalCollisionInfo;
			vecTotalCollisionInfo.clear();

			sptr<GridInfo>& gridInfo = iter->second;

			for (AdjacentMeshInfo& adjacentMeshInfo : gridInfo->vecAdjacentMeshInfo)
			{
				string& meshName = adjacentMeshInfo.meshName;
				sptr<Mesh>& mesh = mapMesh[meshName];

				bool isTerrain = meshName.find("Terrain") != std::string::npos ? true : false;
				if (isTerrain)
				{
					// mesh, adjacentTriangleInfo, position, radius
					CollisionInfo terrainCollisionInfo = GetBestCollisionInfo_From_Terrain(mesh, adjacentMeshInfo.adjacentTriangleIndices, position, radius);
					if (terrainCollisionInfo.IsCollided())
					{
						vecTotalCollisionInfo.push_back(terrainCollisionInfo);
					}
				}
				else
				{
					vector<CollisionInfo> vecCollisionInfo = GetBestCollisionInfo_From_Object(mesh, adjacentMeshInfo.adjacentTriangleIndices, position, radius);

					for (CollisionInfo& collisionInfo : vecCollisionInfo)
					{
						vecTotalCollisionInfo.push_back(collisionInfo);
					}
				}
			}

			Vector3 addPosition;

			for (CollisionInfo& collisionInfo : vecTotalCollisionInfo)
			{
				addPosition = addPosition + (collisionInfo.penetrationNormal * collisionInfo.penetrationDepth);
			}

			vecTotalCollisionInfo.clear();

			return position + addPosition;
		}

		// Terrain 과의 가장 정확한 충돌 정보 중 가장 정확한 정보 단 1개 리턴한다.
	private:
		CollisionInfo GetBestCollisionInfo_From_Terrain(sptr<Mesh>& mesh, vector<int>& triangleIndicesToCheck, Vector3& position, float radius)
		{
			static vector<CollisionInfo> vecCollisionInfo;
			static  CollisionInfo defaultCollisionInfo;
			vecCollisionInfo.clear();

			for (int& triangleIndex : triangleIndicesToCheck)
			{
				sptr<Triangle>& triangle = mesh->vecTriangle[triangleIndex];

				CollisionInfo collisionInfo = CollisionTestUtil::CheckCollision_BetweenTriangleSphere(triangle, position, radius);
				//CollisionInfo collisionInfo;
				if (collisionInfo.IsCollided())
				{
					/*collisionInfo.fromMeshName = mesh->name;
					collisionInfo.fromTriangle = triangle;*/

					vecCollisionInfo.push_back(collisionInfo);
				}
			}

			if (vecCollisionInfo.size() == 0)
			{
				return defaultCollisionInfo;
			}

			float maxPenetraion = (std::numeric_limits<float>::min)();
			CollisionInfo finalCollisionInfo; // 가장 정확한 충돌 정보

			// 가장 정확한 충돌은 penetrationDepth 가 가장 큰 충돌이다.
			for (CollisionInfo& collisionInfo : vecCollisionInfo)
			{
				if (maxPenetraion < collisionInfo.penetrationDepth)
				{
					maxPenetraion = collisionInfo.penetrationDepth;
					finalCollisionInfo = collisionInfo;
				}
			}

			// 경사의 미끄러짐을 방지한다면 충돌이 경사로에서 발생했는지 체크 후 resolve
			// 해준다
			if (CollisionTestUtil::IsCollidedFromSlope(finalCollisionInfo))
			{
				finalCollisionInfo = CollisionTestUtil::ResolveSlope(finalCollisionInfo);
			}

			return finalCollisionInfo;
		}

		// Object 와의 충돌한 정보 중 DotProductType 별로 가장 정확한 충돌 정보를
		// 리턴한다.
		vector<CollisionInfo> GetBestCollisionInfo_From_Object(sptr<Mesh>& mesh, vector<int>& triangleIndicesToCheck, Vector3 position, float radius)
		{
			// Ver1 - Vector3(1,0,0) 와 DotProduct를 계산해서 음수, 0, 양수에 해당하는
			// normal들의 충돌 정보를 vec 에 모은다.(비슷한 방향에서 발생한 충돌 정보
			// 중 가장 정확한 것만 적용하기 위함
			map<DotProductType, vector<CollisionInfo>> map_direction_to_vecCollision;

			Vector3 criteria;

			// 충돌한 모든 정보를 DotProductType 기준으로 모은다.
			for (int& triangleIndex : triangleIndicesToCheck)
			{
				sptr<Triangle>& triangle = mesh->vecTriangle[triangleIndex];

				CollisionInfo collisionInfo = CollisionTestUtil::CheckCollision_BetweenTriangleSphere(triangle, position, radius);
				if (collisionInfo.IsCollided())
				{
					/*collisionInfo.fromMeshName = mesh->name;
					collisionInfo.fromTriangle = triangle;*/

					// 여기서 2가지 방법의 장단점이 있다.
					// 방법 1 : 충돌한 Normal 방향들 중 비슷한 방향들을 그룹으로 묶은 뒤
					// Normal 별로 가장 정확한 Collision Info를 찾기 위함 장점 : 건물 내부의
					// 벽에서 밖으로 나가려고 할 때 jittering이 발생하지 않는다 왼벽 앞벽의
					// 충돌을 모두 처리해주기 때문, 방법 2로 하면 jiterring 발생
					//
					// 방법 2 : Normal 방향 상관없이 Mesh에서 가장 정확한 Collision Info 단
					// 하나만 찾기 방법 2 단점 : 여러 물체와 충돌해서 꼈을 때 jittering
					// 발생, 모서리에 끼었다가 빠져나갈 때 가속도가 붙는 느낌이 있다

					// HISTORY - 모두 DotProductType::NONE 를 key로 넣어준 이유는 하나의
					// Mesh에서 발생한 단 하나의 Collision Info만 체크해줘보자
					// DotProductType type = DotProductType::NONE;

					if (criteria.IsNull())
					{
						criteria = collisionInfo.penetrationNormal;
					}

					DotProductType type = CollisionTestUtil::GetDotProductTypeBetween(criteria, collisionInfo.penetrationNormal);

					map_direction_to_vecCollision[type].push_back(collisionInfo);
				}
			}

			vector<CollisionInfo> vecFinalCollisionInfo;

			// 같은 방향(normal)으로 충돌한 정보 중 가장 정확한 정보만 찾는다.(같은
			// 방향(normal)으로 충돌이 발생 했을 경우 가장 정확한 충돌 방향은
			// penetrationDepth가 가장 큰 값일 때 이다)
			for (auto& [_, vecCollisionInfo] : map_direction_to_vecCollision)
			{
				float maxPenetraion = (std::numeric_limits<float>::min)();
				CollisionInfo finalCollisionInfo; // 가장 정확한 충돌 정보

				// 이 normal의 충돌 정보 중 가장 정확한 정보만 찾는다.
				for (CollisionInfo& collisionInfo : vecCollisionInfo)
				{
					if (maxPenetraion < collisionInfo.penetrationDepth)
					{
						maxPenetraion = collisionInfo.penetrationDepth;
						finalCollisionInfo = collisionInfo;
					}
				}

				// 경사로 미끄러짐 방지가 필요하다면 처리해준다.
				if (CollisionTestUtil::IsCollidedFromSlope(finalCollisionInfo))
				{
					finalCollisionInfo = CollisionTestUtil::ResolveSlope(finalCollisionInfo);
				}

				// 이 normal의 충돌 정보 중 가장 정확한 정보만 리턴 값에 넣어준다.
				vecFinalCollisionInfo.push_back(finalCollisionInfo);
			}

			return vecFinalCollisionInfo;
		}
	};
} // namespace PhysicsEngine
