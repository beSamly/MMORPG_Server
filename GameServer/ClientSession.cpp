#include "pch.h"
#include "ClientSession.h"
#include "PacketHeader.h"
#include "spdlog/spdlog.h"

ClientSession::ClientSession(sptr<asio::io_context> context) : AsioSession(context)
{

}

ClientSession::~ClientSession()
{
	spdlog::debug("[ClientSession] deconstructed");
}

void ClientSession::Send(sptr<Packet>& packet)
{
	//version 1
	//AsioSession::Send(packet.GetByteBuffer(), packet.GetSize());

	 AsioSession::Send(packet->GetBuffer());
}

void ClientSession::Send(Packet& packet)
{
    // version 1
    // AsioSession::Send(packet.GetByteBuffer(), packet.GetSize());

    AsioSession::Send(packet.GetBuffer());
}
