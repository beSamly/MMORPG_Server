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
	// Open the file
	ifstream file(FILE_PATH);

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
		sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
		mesh->name = jsonMesh["meshName"].GetString();

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

			mesh->vecTriangle.push_back(triangle);
		}

		navigationAgent->AddMesh(mesh);
	}

	const auto& listGridInfo = d["listGridInfo"].GetArray();
	for (auto& jsonGridInfo : listGridInfo)
	{
		sptr<PhysicsEngine::GridInfo> gridInfo = make_shared<PhysicsEngine::GridInfo>();
		gridInfo->gridIndex = jsonGridInfo["gridIndex"].GetString();

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
			gridInfo->vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
		}

		navigationAgent->AddGridInfo(gridInfo);
	}

	mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);

	return;
}


void NavigationMeshAgentManager::LoadSceneDataWithSimdjson()
{
	ondemand::parser parser;

	padded_string json = padded_string::load(FILE_PATH);
	simdjson_result d = parser.iterate(json);
	if (d.error()) {
		assert(false);
		return;
	}

	//-----
	sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();
	navigationAgent->sceneName = d["sceneName"].get_string().value();

	int gridSize = d["gridSize"].get_int64();
	navigationAgent->SetGridSize(gridSize);

	vector<PhysicsEngine::Mesh> vecMesh;

	for (ondemand::object jsonMesh : d["listMesh"]) {

		sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
		mesh->name = jsonMesh["meshName"].get_string().value();

		for (ondemand::object jsonTriangle : jsonMesh["listTriangle"])
		{
			vector<PhysicsEngine::Vector3> vertices;

			for (ondemand::object jsonVertex : jsonTriangle["vertices"])
			{
				PhysicsEngine::Vector3 vertex;
				vertex.x = jsonVertex["x"].get_double();
				vertex.y = jsonVertex["y"].get_double();
				vertex.z = jsonVertex["z"].get_double();

				vertices.push_back(vertex);
			}

			PhysicsEngine::Triangle triangle(vertices[0], vertices[1], vertices[2]);
			triangle.name = jsonTriangle["triangleName"].get_string().value();

			mesh->vecTriangle.push_back(triangle);
		}

		navigationAgent->AddMesh(mesh);
	}

	for (ondemand::object jsonGridInfo : d["listGridInfo"])
	{
		sptr<PhysicsEngine::GridInfo> gridInfo = make_shared<PhysicsEngine::GridInfo>();
		gridInfo->gridIndex = jsonGridInfo["gridIndex"].get_string().value();

		for (ondemand::object jsonAdjacentTriangleInfo : jsonGridInfo["listAdjacentMeshInfo"])
		{
			PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
			adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"].get_string().value();

			for (int index : jsonAdjacentTriangleInfo["adjacentTriangleIndices"])
			{
				adjacentMeshInfo.adjacentTriangleIndices.push_back(index);
			}
			gridInfo->vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
		}

		navigationAgent->AddGridInfo(gridInfo);
	}

	mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);

	return;
}

void NavigationMeshAgentManager::LoadSceneDataWithSimdjson()
{
    ondemand::parser parser;

    padded_string json = padded_string::load(FILE_PATH);
    simdjson_result d = parser.iterate(json);
    if (d.error())
    {
        assert(false);
        return;
    }

    sptr<PhysicsEngine::NavigationMeshAgent> navigationAgent = make_shared<PhysicsEngine::NavigationMeshAgent>();
    navigationAgent->sceneName = d["sceneName"].get_string().value();

    int gridSize = d["gridSize"].get_int64();
    navigationAgent->SetGridSize(gridSize);

    vector<PhysicsEngine::Mesh> vecMesh;

    for (ondemand::object jsonMesh : d["listMesh"])
    {
        /*sptr<PhysicsEngine::Mesh> mesh = make_shared<PhysicsEngine::Mesh>();
        mesh->name = jsonMesh["meshName"].get_string().value();*/

        for (ondemand::object jsonTriangle : jsonMesh["listTriangle"])
        {
            vector<PhysicsEngine::Vector3> vertices;

            for (ondemand::object jsonVertex : jsonTriangle["vertices"])
            {
                PhysicsEngine::Vector3 vertex;
                vertex.x = jsonVertex["x"].get_double();
                vertex.y = jsonVertex["y"].get_double();
                vertex.z = jsonVertex["z"].get_double();

                //vertices.push_back(vertex);
            }

            //PhysicsEngine::Triangle triangle(vertices[0], vertices[1], vertices[2]);
            //triangle.name = jsonTriangle["triangleName"].get_string().value();

            //mesh->vecTriangle.push_back(triangle);
        }

        //navigationAgent->AddMesh(mesh);
    }

    for (ondemand::object jsonGridInfo : d["listGridInfo"])
    {
        sptr<PhysicsEngine::GridInfo> gridInfo = make_shared<PhysicsEngine::GridInfo>();
        gridInfo->gridIndex = jsonGridInfo["gridIndex"].get_string().value();

        for (ondemand::object jsonAdjacentTriangleInfo : jsonGridInfo["listAdjacentMeshInfo"])
        {
            PhysicsEngine::AdjacentMeshInfo adjacentMeshInfo;
            adjacentMeshInfo.meshName = jsonAdjacentTriangleInfo["meshName"].get_string().value();

            for (auto index : jsonAdjacentTriangleInfo["adjacentTriangleIndices"])
            {
                adjacentMeshInfo.adjacentTriangleIndices.push_back(index.get_int64());
            }

            //gridInfo->vecAdjacentMeshInfo.push_back(adjacentMeshInfo);
        }

        //navigationAgent->AddGridInfo(gridInfo);
    }

    //mapNavigationMeshAgent.emplace(navigationAgent->sceneName, navigationAgent);

    return;
}
