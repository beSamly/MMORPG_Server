#include "pch.h"
#include <fstream>
#include "NavigationMeshAgentManager.h"
#include "nlohmann/json.hpp"
#include "PhysicsEngine.h"

using json = nlohmann::json;

void NavigationMeshAgentManager::LoadJsonData() { LoadSceneData(); }

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
    std::ifstream f("./json/NavigationMeshAgentData.json");

    json d = json::parse(f);

    sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();

    navigationAgent->sceneName = d["sceneName"];
    int gridSize = d["gridSize"];

    navigationAgent->SetGridSize(gridSize);

    vector<PhysicsEngine::Mesh> vecMesh;

    json listMesh = d["listMesh"];
    for (auto& jsonMesh : listMesh)
    {
        PhysicsEngine::Mesh mesh;
        mesh.name = jsonMesh["meshName"];

        json listTriangle = jsonMesh["listTriangle"];
        for (auto& jsonTriangle : listTriangle)
        {
            PhysicsEngine::Triangle triangle;
            triangle.name = jsonTriangle["triangleName"];

            json vertices = jsonMesh["vertices"];
            for (auto& jsonVertex : vertices)
            {
                PhysicsEngine::Vector3 vertex;
                vertex.x = jsonVertex['x'];
                vertex.y = jsonVertex['y'];
                vertex.z = jsonVertex['z'];

                triangle.vertices.push_back(vertex);
            }

            mesh.vecTriangle.push_back(triangle);
        }

        navigationAgent->AddMesh(mesh);
    }

    vector<PhysicsEngine::GridInfo> vecGridInfo;

    json listGridInfo = d["listGridInfo"];
    for (auto& jsonGridInfo : listGridInfo)
    {
        PhysicsEngine::GridInfo gridInfo;
        gridInfo.gridIndex = jsonGridInfo["gridIndex"];

        json listAdjacentTriangleInfo = jsonGridInfo["vecAdjacentMeshInfo"];
        for (auto& jsonAdjacentTriangleInfo : listAdjacentTriangleInfo)
        {
            PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
            adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"];

            json listAdjacentTriangleIndices = jsonAdjacentTriangleInfo["adjacentTriangleIndices"];
            for (auto& index : listAdjacentTriangleIndices)
            {
                adjacentMeshInfo.adjacentTriangleIndices.push_back(index);
            }
            gridInfo.vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
        }

        navigationAgent->AddGridInfo(gridInfo);
    }

    mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);
}
