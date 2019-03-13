/*
*Auther: HuaWeiLi
*Date: 2019.03.02
*FileDesc: accept() 返回的连接
*/
#include "TcpConnection.h"

TcpConnection::TcpConnection(Socket::NativeSocket socket) :
    TcpStream(socket)
{
}

TcpConnection::~TcpConnection()
{

}

const std::string& TcpConnection::GegtHost() const
{
    return _host;
}

uint16_t TcpConnection::GetPort() const
{
    return _port;
}

void TcpConnection::SetAddress(const Socket::NativeAddress& address)
{
    static const int HOST_STR_SIZE=255;
    char hostStr[HOST_STR_SIZE];
    inet_ntop(AF_INET,&address.sin_addr,hostStr,sizeof(hostStr));

    _host = hostStr;
    _port = ntohs(address.sin_port);
}