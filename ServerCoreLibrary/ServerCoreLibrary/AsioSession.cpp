#pragma once
#include "pch.h"
#include "AsioSession.h"
#include <asio/io_context.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#include "asio.hpp"
#include "PacketHeader.h"

AsioSession::AsioSession(shared_ptr<asio::io_context> context)
    : socket(*context), /*resolver(*context),*/ sendBufferQueue(MAX_LENGTH), recvBuffer(MAX_LENGTH)
{
}

AsioSession::AsioSession(tcp::socket p_socket)
    : socket(std::move(p_socket)), sendBufferQueue(MAX_LENGTH), recvBuffer(MAX_LENGTH)
{
}

AsioSession::~AsioSession() {}

void AsioSession::DoRead()
{
    auto self(shared_from_this());
    socket.async_read_some(asio::buffer(recvBuffer.WritePos(), MAX_LENGTH),
                           [this, self](std::error_code ec, std::size_t length)
                           {
                               if (!ec)
                               {
                                   if (recvBuffer.OnWrite(length) == false)
                                   {
                                       std::cout << "[TODO] OnWrite Overflow" << std::endl;
                                       // Disconnect(L"OnWrite Overflow");
                                       return;
                                   }

                                   int dataSize = recvBuffer.DataSize();
                                   int processLen = OnRecv(recvBuffer.ReadPos(),
                                                           dataSize); // 컨텐츠 코드에서 재정의
                                   if (processLen < 0 || dataSize < processLen ||
                                       recvBuffer.OnRead(processLen) == false)
                                   {
                                       // Disconnect(L"OnRead Overflow");
                                       std::cout << "[TODO] OnRead Overflow" << std::endl;
                                       return;
                                   }

                                   // 커서 정리
                                   recvBuffer.Clean();

                                   DoRead();
                               }
                               else
                               {
                                   // OnError();
                                   socket.close();
                                   OnDisconnect(ec);
                               }
                           });
}

void AsioSession::Send(BYTE* byteBuffer, uint32 size) {}

void AsioSession::Send(shared_ptr<Buffer> buffer)
{
    // TODO 일단 write_lock으로 하지만 나중에는 queue로 변경?
    WRITE_LOCK;
    sendBufferQueue.PushBuffer(buffer);

    // [TODO] 큐에 담아서 한번에 보내는 로직 수정이 좀 필요
    /*bool isSending = true;
    if (atomicIsSending.exchange(true) == false)
    {
        isSending = false;
    }

    if (isSending)
    {
        std::cout << "is already sending" << std::endl;
        return;
    }*/

    RegisterSend();
}

void AsioSession::RegisterSend()
{
    auto self(shared_from_this());

    int totalSize;
    BYTE* buffer = sendBufferQueue.GetAllData(totalSize);

    asio::async_write(socket, asio::buffer(buffer, totalSize),
                      [this, self](std::error_code ec, std::size_t /*length*/)
                      {
                          if (!ec)
                          {
                              // Echo Server 예제를 봐서 DoRead를 호출한 것 같은데 이렇게 될 경우 소켓 연결 끊어질 때
                              // Send함수 보낸 만큼 async_read_some 함수에 인자로 넘긴 콜백이 실행된다.. DoRead();
                              atomicIsSending.store(false);
                          }
                          else
                          {
                              socket.close();
                              OnDisconnect(ec);
                          }
                      });
}

void AsioSession::Connect(string address, int port)
{
    asio::ip::tcp::endpoint ep(asio::ip::address::from_string(address), port);
    socket.async_connect(ep,
                         [this](const asio::error_code& ec)
                         {
                             if (!ec)
                             {
                                 OnConnect();
                             }
                             else
                             {
                                 socket.close();
                                 OnDisconnect(ec);
                             }
                         });
}

int AsioSession::OnRecv(BYTE* buffer, int len)
{
    int32 processLen = 0;

    while (true)
    {
        int32 dataSize = len - processLen;
        // 데이터 사이즈가 헤더 사이즈 보다 작을 순 없다
        if (dataSize < sizeof(PacketHeader))
            break;

        PacketHeader header = *(reinterpret_cast<PacketHeader*>(&buffer[processLen]));
        // 헤더에 기록된 패킷 크기를 파싱할 수 있어야 한다
        if (dataSize < header.size)
            break;

        // 패킷 조립 성공
        OnRecvCallback(shared_from_this(), &buffer[processLen], header.size);
        processLen += header.size;
    }

    return processLen;
}

void AsioSession::OnConnect() { OnConnectCallback(shared_from_this()); }

void AsioSession::OnDisconnect(std::error_code err) { OnDisconnectCallback(shared_from_this(), err); }

std::shared_ptr<AsioSession> AsioSession::GetSessionRef() { return shared_from_this(); }