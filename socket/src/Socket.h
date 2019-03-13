#pragma once

#include <unistd.h>
#include <arpa/inet.h>

// 主socket类,用于客户端套接字和服务器套接字继承
class Socket
{
public:
    using NativeSocket = int;
    using NativeAddress = struct sockaddr_in;

    Socket(NativeSocket socket);
    virtual ~Socket();

    void Close();

protected:
    NativeSocket _socket;
};

