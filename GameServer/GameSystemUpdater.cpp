#include "pch.h"
#include "GameSystemUpdater.h"
#include "PacketDef.h"
#include "Vector3.pb.h"
#include "NPCSpawned.pb.h"
#include "NPC.h"
#include "TransformEntity.h"

using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_POSITION;

GameSystemUpdater::GameSystemUpdater(sptr<GameSystem> gameSystem) { reqControllerContainer = make_unique<GameSystemControllerContainer>(gameSystem); }

void GameSystemUpdater::UpdateEachScene(float deltaTime, sptr<Scene>& scene, vector<sptr<Player>>& playersInScene)
{
    elapsedTime += deltaTime;

    ProcessSceneReqQueue(scene);
    UpdateSpawnManager(scene, playersInScene);
    UpdateNPC(deltaTime, scene);

    if (elapsedTime - lastChecked > 2)
    {
        // ��� �÷��̾��� ��ġ�� ��� �÷��̿��� ����ȭ
        //player->SendUpdatePosition();

        // ��� NPC�� ��ġ�� ��� �÷��̾�� ����ȭ
        lastChecked = elapsedTime;
    }
}

void GameSystemUpdater::UpdateEachPlayer(float deltaTime, sptr<Scene>& scene, sptr<Player>& player, vector<sptr<Player>>& others)
{
    // �÷��̾� ������ ��ü ������Ʈ
    player->Update(deltaTime);

    //[TODO]
    float radius = 0.5f; // Unity�� this.GetComponent<SphereCollider>().radius ��

    // ������ �浹 ó��
    Vector3 currentPosition = player->GetPosition();
    Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, radius);
    player->SetPosition(newPosition);

    // queue<Operation> readyOperation = player->skillController->GetReadyOperation();

    // while (!readyOperation.empty())
    //{
    //	Operation& operation = readyOperation.front();

    //	//smt like operation->trigger()
    //	//operation.opereationType

    //	readyOperation.pop();
    //}
}

void GameSystemUpdater::ProcessSceneReqQueue(sptr<Scene>& scene)
{
    // Ŀ�ǵ� ���� ó��
    queue<sptr<BaseReq>> copied = scene->FlushQueue();
    while (!copied.empty())
    {
        sptr<BaseReq> command = copied.front();
        int commandId = command->GetCommandId();

        sptr<IGameSystemController> controller = reqControllerContainer->GetController(command->commandGroupId);
        if (controller)
        {
            controller->Process(scene, command);
        }
        else
        {
            LOG_ERROR("GameSystemControllerContainer has no controller for commandGroupId = " + command->commandGroupId);
        }
        copied.pop();
    }
}

void GameSystemUpdater::UpdateSpawnManager(sptr<Scene>& scene, vector<sptr<Player>>& players)
{
    vector<sptr<TransformEntity>> readyToSpawn = scene->spawnManager->GetReadyToSpawn();
    for (sptr<TransformEntity> transformEntity : readyToSpawn)
    {
        scene->npcManager->AddNPC(transformEntity);

        sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
        if (npc == nullptr)
        {
            LOG_ERROR("TrnasformEntity is not NPC object");
            continue;
        }

        SendNPCSpawned(npc, players);
    }
}

void GameSystemUpdater::SendNPCSpawned(sptr<NPC>& npc, vector<sptr<Player>>& players)
{
    Protocol::NPCSpawned npcSpawned;
    npcSpawned.mutable_position()->set_x(0.0f);
    npcSpawned.mutable_position()->set_y(0.0f);
    npcSpawned.mutable_position()->set_z(0.0f);

    npcSpawned.mutable_npcinfo()->set_npcid(npc->npcId);
    npcSpawned.mutable_npcinfo()->set_npcindex(npc->npcIndex);
    npcSpawned.mutable_npcinfo()->set_npcname(npc->npcName);

    npcSpawned.mutable_statinfo()->set_maxhp(npc->GetStat(STAT_TYPE::MAX_HP));
    npcSpawned.mutable_statinfo()->set_maxmp(npc->GetStat(STAT_TYPE::MAX_MP));
    npcSpawned.mutable_statinfo()->set_armor(npc->GetStat(STAT_TYPE::ARMOR));
    npcSpawned.mutable_statinfo()->set_attackpower(npc->GetStat(STAT_TYPE::ATTACK_POWER));
    npcSpawned.mutable_statinfo()->set_attackspeed(npc->GetStat(STAT_TYPE::ATTACK_SPEED));
    npcSpawned.mutable_statinfo()->set_magicpower(npc->GetStat(STAT_TYPE::MAGIC_POWER));
    npcSpawned.mutable_statinfo()->set_magicresistance(npc->GetStat(STAT_TYPE::MAGIC_RESISTANCE));
    npcSpawned.mutable_statinfo()->set_movespeed(npc->GetStat(STAT_TYPE::MOVE_SPEED));

    Packet packet(PACKET_GROUP_ID::POSITION, PACKET_ID_POSITION::NPC_SPAWNED);
    packet.WriteData<Protocol::NPCSpawned>(npcSpawned);

    for (const sptr<Player>& player : players)
    {
        player->Send(packet);
    }
}

void GameSystemUpdater::UpdateNPC(float deltaTime, sptr<Scene>& scene)
{
    vector<sptr<TransformEntity>> vecNPC = scene->npcManager->getAllNpc();

    for (sptr<TransformEntity> transformEntity : vecNPC)
    {
        sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
        if (npc == nullptr)
        {
            LOG_ERROR("Can not convert TransformEntity to NPC");
            continue;
        }

        // �÷��̾� ������ ��ü ������Ʈ
        npc->Update(deltaTime);

        if (npc->patrolController->NeedToSwitchMoveDirection())
        {
            npc->patrolController->SwitchToNextMoveDirection();
            Vector3 newDirection = npc->patrolController->GetCurrentMoveDirection();

            //��� Player���� npc�� move direction ����ȭ!

        }

        //[TODO]
        float radius = 0.5f; // Unity�� this.GetComponent<SphereCollider>().radius ��

        // ������ �浹 ó��
        Vector3 currentPosition = npc->GetPosition();
        Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, radius);
        npc->SetPosition(newPosition);

        if (elapsedTime - lastChecked > 2)
        {
            // player->SendUpdatePosition();
            lastChecked = elapsedTime;
        }
    }
}
