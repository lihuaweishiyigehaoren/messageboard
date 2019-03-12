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
