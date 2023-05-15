#include "pch.h"
#include <fstream>
#include "NavigationMeshAgentManager.h"
#include "PhysicsEngine.h"
#include "simdjson.h"
#include <spdlog/spdlog.h>

using namespace simdjson;

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

void NavigationMeshAgentManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;

	auto error = parser.load(GetFilePath()).get(data);
	if (error) {
		spdlog::error("Failed to parse {}", GetFilePath());
		assert(false);
	};

	sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();
	navigationAgent->sceneName = data["sceneName"];

	int gridSize = data["gridSize"].get_int64();
	navigationAgent->SetGridSize(gridSize);

	// Iterate through an array of objects
	for (const dom::element& jsonMesh : data["listMesh"])
	{

		sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
		mesh->name = jsonMesh["meshName"].get_string().value();

		for (const dom::element& jsonTriangle : jsonMesh["listTriangle"])
		{
			vector<sptr<PhysicsEngine::Vector3>> vertices;

			for (const dom::element& jsonVertex : jsonTriangle["vertices"])
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

	mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);
}
