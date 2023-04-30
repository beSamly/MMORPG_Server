#include "pch.h"
#include <fstream>
#include "NPCInfoManager.h"
#include <rapidjson/document.h>

using namespace rapidjson;

void NPCInfoManager::LoadJsonData()
{
    // Open the file
    std::ifstream file("./json/NPCInfo.json");

    // Read the entire file into a string
    string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

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

    const auto& listNPCInfo = d.GetArray();

    for (auto& jsonNPCInfo : listNPCInfo)
    {
        NPCInfo npcInfo;

        npcInfo.npcIndex = jsonNPCInfo["NPCIndex"].GetInt();
        npcInfo.npcName = jsonNPCInfo["NPCName"].GetString();
        npcInfo.BaseStatIndex = jsonNPCInfo["BaseStatIndex"].GetInt();

        mapNPCInfo[npcInfo.npcIndex] = npcInfo;
    }
}

NPCInfo NPCInfoManager::GetNPCInfo(int npxIndex)
{
    auto iter = mapNPCInfo.find(npxIndex);

    if (iter != mapNPCInfo.end())
    {
        return iter->second;
    }
    else
    {
        return NPCInfo();
    }
}
