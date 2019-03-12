/*
*Auther: HuaWeiLi
*Date: 2019.03.02
*FileDesc: accept() 返回的连接
*/
#include "TcpStream.h"

TcpStream::TcpStream(Socket::NativeSocket socket) :
    Socket(socket)
{
}

TcpStream::~TcpStream()
{
}

ssize_t TcpStream::Send(const void* buffer,size_t len)
{
    return 0;
}

ssize_t TcpStream::Receive(void* buffer,size_t len)
{
    return 0;
}

ssize_t TcpStream::write(const void * buffer,size_t len)
{
    return 0;
}
ssize_t TcpStream::read(void * buffer,size_t len)
{
    return 0;
}