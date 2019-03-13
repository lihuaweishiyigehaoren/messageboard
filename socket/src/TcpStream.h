#pragma once

#include "Socket.h"

class TcpStream : public Socket
{
private:
    /* data */
public:
    TcpStream(Socket::NativeSocket socket);
    ~TcpStream();

    ssize_t Write(const void * buffer,size_t len);// 向客户端写数据
    ssize_t Read(void * buffer,size_t len);// 从客户端读数据

private:
    // size_t 适于计量内存中可容纳的数据项目个数的无符号整数类型 ssize_t便于移植
    ssize_t Send(const void* buffer,size_t len);
    ssize_t Receive(void* buffer,size_t len);
};
