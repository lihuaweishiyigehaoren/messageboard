/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "Socket.h"

Socket::Socket(NativeSocket socket) : 
    _socket(socket)
{
}

Socket::~Socket()
{
    Close();
}

// 释放套接字资源
void Socket::Close()
{
    if(_socket)
    {
        // 与shutdown区别,只关闭当前进程的连接,其他共享套接字的连接依然存在
        close(_socket);
    }
}