#pragma once
#include "Player.h"
#include "Scene.h"
#include "NPC.h"
#include "RequestControllerContainer.h"

class GameSystem;
class RequestControllerContainer;

class GameSystemUpdater
{
private:
	float lastChecked = 0.0f;
	float elapsedTime = 0.0f;

	uptr<RequestControllerContainer> reqControllerContainer;

public:

	GameSystemUpdater(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem);
	void UpdateEachScene(float deltaTime, sptr<Scene>& scene, vector<sptr<Player>>& playersInScene);
	void UpdateEachPlayer(float deltaTime, sptr<Scene>& scene, sptr<Player>& player, vector<sptr<Player>>& others);
	void UpdateEachNPC(float deltaTime, sptr<Scene>& scene, sptr<NPC>& npc);

private:
	void ProcessRequestQueue(sptr<Scene>& scene);
	void SendNPCSpawnedToPlayer(sptr<NPC>& npc, vector<sptr<Player>>& players);
	void SendPositionUpdateToPlayer(sptr<TransformEntity>& transform, vector<sptr<Player>>& players);

	void SyncPlayerPosition(vector<sptr<Player>>& players);
	void SyncNPCPosition(vector<sptr<Player>>& players, vector<sptr<TransformEntity>> npcs);
	Packet BuildUpdatePositionPacket(sptr<TransformEntity> transform);
};