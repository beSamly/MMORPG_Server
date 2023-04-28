#include "pch.h"
#include <fstream>
#include "NavigationMeshAgentManager.h"
#include "PhysicsEngine.h"
#include "rapidjson/document.h"

using std::ifstream;
using std::istreambuf_iterator;
using namespace rapidjson;

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
    // Open the file
    ifstream file("./json/NavigationMeshAgentData.json");

    // Read the entire file into a string
    string jsonStr((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Create a Document object
    // to hold the JSON data
    Document d;

    // Parse the JSON data
    d.Parse(jsonStr.c_str());

    // Check for parse errors
    if (d.HasParseError())
    {
        std::cerr << "Error parsing JSON: " << d.GetParseError() << std::endl;
        assert(false);
        return;
    }

    sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();

    navigationAgent->sceneName = d["sceneName"].GetString();

    int gridSize = d["gridSize"].GetInt();

    navigationAgent->SetGridSize(gridSize);

    vector<PhysicsEngine::Mesh> vecMesh;

    const auto& listMesh = d["listMesh"].GetArray();
    for (auto& jsonMesh : listMesh)
    {
        PhysicsEngine::Mesh mesh;
        mesh.name = jsonMesh["meshName"].GetString();

        const auto& listTriangle = jsonMesh["listTriangle"].GetArray();
        for (auto& jsonTriangle : listTriangle)
        {
            vector<PhysicsEngine::Vector3> vertices;
            const auto& jsonVertices = jsonTriangle["vertices"].GetArray();
            for (auto& jsonVertex : jsonVertices)
            {
                PhysicsEngine::Vector3 vertex;
                vertex.x = jsonVertex["x"].GetFloat();
                vertex.y = jsonVertex["y"].GetFloat();
                vertex.z = jsonVertex["z"].GetFloat();

                vertices.push_back(vertex);
            }

            PhysicsEngine::Triangle triangle(vertices[0], vertices[1], vertices[2]);
            triangle.name = jsonTriangle["triangleName"].GetString();
     
            mesh.vecTriangle.push_back(triangle);
        }

        navigationAgent->AddMesh(mesh);
    }

    vector<PhysicsEngine::GridInfo> vecGridInfo;

    const auto& listGridInfo = d["listGridInfo"].GetArray();
    for (auto& jsonGridInfo : listGridInfo)
    {
        PhysicsEngine::GridInfo gridInfo;
        gridInfo.gridIndex = jsonGridInfo["gridIndex"].GetString();

        const auto& listAdjacentTriangleInfo = jsonGridInfo["listAdjacentMeshInfo"].GetArray();
        for (auto& jsonAdjacentTriangleInfo : listAdjacentTriangleInfo)
        {
            PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
            adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"].GetString();

            const auto& listAdjacentTriangleIndices = jsonAdjacentTriangleInfo["adjacentTriangleIndices"].GetArray();
            for (auto& index : listAdjacentTriangleIndices)
            {
                adjacentMeshInfo.adjacentTriangleIndices.push_back(index.GetInt());
            }
            gridInfo.vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
        }

        navigationAgent->AddGridInfo(gridInfo);
    }

    mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);

    return;
}
