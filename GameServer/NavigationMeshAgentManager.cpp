#include "pch.h"
#include <fstream>
#include "NavigationMeshAgentManager.h"
#include "PhysicsEngine.h"
#include "rapidjson/document.h"
#include "simdjson.h"

using std::ifstream;
using std::istreambuf_iterator;
using namespace rapidjson;
using namespace simdjson;

void NavigationMeshAgentManager::LoadJsonData()
{
	{
		std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
		//LoadSceneData();
		auto now = std::chrono::steady_clock::now();
		float elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
		LOG_INFO("Elapsed Ver1 : " + std::to_string(elapsed));
	}

	{
		std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
		LoadSceneDataWithSimdjson();
		auto now = std::chrono::steady_clock::now();
		float elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
		LOG_INFO("Elapsed Ver2 : " + std::to_string(elapsed));
	}
}

sptr<PhysicsEngine::NavigationMeshAgent> NavigationMeshAgentManager::GetNavigationMeshAgent(string sceneName)
{
	if (mapNavigationMeshAgent.count(sceneName))
	{
		return mapNavigationMeshAgent[sceneName];
	}
	else
	{
		return nullptr;
	}
}

void NavigationMeshAgentManager::LoadSceneData()
{
	//// Open the file
	//ifstream file(FILE_PATH);

	//// Read the entire file into a string
	//string jsonStr((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

	//// Create a Document object
	//// to hold the JSON data
	//Document d;

	//// Parse the JSON data
	//d.Parse(jsonStr.c_str());

	//// Check for parse errors
	//if (d.HasParseError())
	//{
	//	std::cerr << "Error parsing JSON: " << d.GetParseError() << std::endl;
	//	assert(false);
	//	return;
	//}

	//sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();

	//navigationAgent->sceneName = d["sceneName"].GetString();

	//int gridSize = d["gridSize"].GetInt();

	//navigationAgent->SetGridSize(gridSize);

	//vector<PhysicsEngine::Mesh> vecMesh;

	//const auto& listMesh = d["listMesh"].GetArray();
	//for (auto& jsonMesh : listMesh)
	//{
	//	sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
	//	mesh->name = jsonMesh["meshName"].GetString();

	//	const auto& listTriangle = jsonMesh["listTriangle"].GetArray();
	//	for (auto& jsonTriangle : listTriangle)
	//	{
	//		vector<PhysicsEngine::Vector3> vertices;
	//		const auto& jsonVertices = jsonTriangle["vertices"].GetArray();
	//		for (auto& jsonVertex : jsonVertices)
	//		{
	//			PhysicsEngine::Vector3 vertex;
	//			vertex.x = jsonVertex["x"].GetFloat();
	//			vertex.y = jsonVertex["y"].GetFloat();
	//			vertex.z = jsonVertex["z"].GetFloat();

	//			vertices.push_back(vertex);
	//		}

	//		PhysicsEngine::Triangle triangle(vertices[0], vertices[1], vertices[2]);
	//		triangle.name = jsonTriangle["triangleName"].GetString();

	//		mesh->vecTriangle.push_back(triangle);
	//	}

	//	navigationAgent->AddMesh(mesh);
	//}

	//const auto& listGridInfo = d["listGridInfo"].GetArray();
	//for (auto& jsonGridInfo : listGridInfo)
	//{
	//	sptr<PhysicsEngine::GridInfo> gridInfo = make_shared<PhysicsEngine::GridInfo>();
	//	gridInfo->gridIndex = jsonGridInfo["gridIndex"].GetString();

	//	const auto& listAdjacentTriangleInfo = jsonGridInfo["listAdjacentMeshInfo"].GetArray();
	//	for (auto& jsonAdjacentTriangleInfo : listAdjacentTriangleInfo)
	//	{
	//		PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
	//		adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"].GetString();

	//		const auto& listAdjacentTriangleIndices = jsonAdjacentTriangleInfo["adjacentTriangleIndices"].GetArray();
	//		for (auto& index : listAdjacentTriangleIndices)
	//		{
	//			adjacentMeshInfo.adjacentTriangleIndices.push_back(index.GetInt());
	//		}
	//		gridInfo->vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
	//	}

	//	navigationAgent->AddGridInfo(gridInfo);
	//}

	//mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);

	return;
}

void NavigationMeshAgentManager::LoadSceneDataWithSimdjson()
{
	std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();

	simdjson::dom::parser parser;

	// dom::parser parser;
	simdjson::dom::element data;
	auto error = parser.load(FILE_PATH).get(data);

	{
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - lastUpdate).count() / 1000000.0f;
		lastUpdate = std::chrono::steady_clock::now();
		std::cout << "Simdjson Ver2 parsing json - elapsed time : " << deltaTime << std::endl;
	}

	sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();
	navigationAgent->sceneName = data["sceneName"];

	int gridSize = data["gridSize"].get_int64();
	navigationAgent->SetGridSize(gridSize);

	// Iterate through an array of objects
	for (const dom::element& jsonMesh : data["listMesh"])
	{

		sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
		mesh->name = jsonMesh["meshName"].get_string().value();

		for (const auto& jsonTriangle : jsonMesh["listTriangle"])
		{
			vector<sptr<PhysicsEngine::Vector3>> vertices;

			for (const auto& jsonVertex : jsonTriangle["vertices"])
			{
				sptr<PhysicsEngine::Vector3> vertex = make_shared<PhysicsEngine::Vector3>();
				vertex->x = jsonVertex["x"].get_double();
				vertex->y = jsonVertex["y"].get_double();
				vertex->z = jsonVertex["z"].get_double();

				vertices.push_back(vertex);
			}

			sptr<PhysicsEngine::Triangle> triangle = make_shared<PhysicsEngine::Triangle>(*vertices[0], *vertices[1], *vertices[2]);
			triangle->name = jsonTriangle["triangleName"].get_string().value();
			mesh->vecTriangle.push_back(triangle);
		}

		navigationAgent->AddMesh(mesh);
	}

	{
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - lastUpdate).count() / 1000000.0f;
		lastUpdate = std::chrono::steady_clock::now();
		std::cout << "Simdjson Ver2 parsing listMesh - elapsed time : " << deltaTime << std::endl;
	}

	for (const auto& jsonGridInfo : data["listGridInfo"])
	{
		sptr<PhysicsEngine::GridInfo> gridInfo = make_shared<PhysicsEngine::GridInfo>();
		gridInfo->gridIndex = jsonGridInfo["gridIndex"].get_string().value();

		for (const auto& jsonAdjacentTriangleInfo : jsonGridInfo["listAdjacentMeshInfo"])
		{
			PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
			adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"].get_string().value();

			for (const auto& index : jsonAdjacentTriangleInfo["adjacentTriangleIndices"])
			{
				adjacentMeshInfo.adjacentTriangleIndices.push_back(index.get_int64());
			}
			gridInfo->vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
		}

		navigationAgent->AddGridInfo(gridInfo);
	}

	{
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - lastUpdate).count() / 1000000.0f;
		lastUpdate = std::chrono::steady_clock::now();
		std::cout << "Simdjson ver2 parsing GridInfo - elapsed time : " << deltaTime << std::endl;
	}

	mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);
}