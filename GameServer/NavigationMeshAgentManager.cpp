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
    for (auto& mesh : listMesh)
    {
        PhysicsEngine::Mesh PEMesh;
        PEMesh.name = mesh["meshName"];

        json listTriangle = mesh["listTriangle"];
        for (auto& triangle : listTriangle)
        {
            PhysicsEngine::Triangle t;
            t.name = triangle["triangleName"];

            json vertices = mesh["vertices"];
            for (auto& vertex : vertices)
            {
                PhysicsEngine::Vector3 vec3;
                vec3.x = vertex['x'];
                vec3.y = vertex['y'];
                vec3.z = vertex['z'];

                t.vertices.push_back(vec3);
            }

            PEMesh.vecTriangle.push_back(t);
        }

        navigationAgent->AddMesh(PEMesh);
    }

    mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);
}
