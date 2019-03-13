/*
*Auther: HuaWeiLi
*Date: 2019.03.13
*FileDesc: init client socket
*/
#include "TcpClientInit.h"
#include <sys/socket.h>
#include <iostream>
#include <cstring>
using namespace std;

TcpClientInit::TcpClientInit() :
    TcpConnection(socket(AF_INET,SOCK_STREAM,0))
{
}

TcpClientInit::~TcpClientInit()
{
}

void TcpClientInit::Connect(const std::string& host,uint16_t port)
{
    if(_socket == -1)
    {
        cout<<"tcp client socket error"<<endl;
    }

    _host = host;
    _port = port;

    Socket::NativeAddress serverAddress;
    memset(&serverAddress,0,sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(_host.c_str());
    serverAddress.sin_port = htons(_port);

    if(connect(_socket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))==-1)
    {
        cout<<"connect server failed"<<endl;
    }
}