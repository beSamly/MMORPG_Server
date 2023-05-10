#pragma once
#include "pch.h"
#include <asio/ip/tcp.hpp>
#include "SendBuffer.h"
#include "RecvBuffer.h"

using asio::ip::tcp;
using std::move;
using std::shared_ptr;

class AsioSession : public std::enable_shared_from_this<AsioSession>
{
public:
	AsioSession(shared_ptr<asio::io_context> context);
	AsioSession(tcp::socket p_socket);
	virtual ~AsioSession();
	tcp::socket socket;

public:
	void Start() { DoRead(); }
	void Send(BYTE* byteBuffer, uint32 size);
	void Connect(string address, int port);

	void SetOnRecvCallback(function<void(std::shared_ptr<AsioSession>, BYTE*, int32)> callback)
	{
		OnRecvCallback = callback;
	}

	void SetOnDisconnectCallback(function<void(std::shared_ptr<AsioSession>, std::error_code err)> callback) { OnDisconnectCallback = callback; }
	void SetOnConnectCallback(function<void(std::shared_ptr<AsioSession>)> callback) { OnConnectCallback = callback; }
	std::shared_ptr<AsioSession> GetSessionRef();

private:
	/* 네트워크 콜백 */
	function<void(std::shared_ptr<AsioSession>, BYTE*, int32)> OnRecvCallback;
	function<void(std::shared_ptr<AsioSession>, std::error_code err)> OnDisconnectCallback;
	function<void(std::shared_ptr<AsioSession>)> OnConnectCallback;

	void DoRead();
	int  OnRecv(BYTE* buffer, int len);
	void OnConnect();
	void OnDisconnect(std::error_code err);

private:
	/* Utility */
	USE_LOCK;

	/* Asio Library */
	//tcp::resolver resolver;

	/* 수신 관련 */
	RecvBuffer recvBuffer;
	int MAX_LENGTH = 0x10000;

	/* 송신 관련 */
	std::queue<shared_ptr<SendBuffer>> sendQueue; // TODO 나중에 packet들 모아서 보내도록 큐에 담기. 아직 사용하는 곳 없다
};