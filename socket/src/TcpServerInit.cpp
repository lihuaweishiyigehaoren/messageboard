/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include <sys/socket.h>
#include <cstring>
#include "TcpServerInit.h"


TcpServerInit::TcpServerInit() : Socket(socket(AF_INET,SOCK_STREAM,0))
{
}

TcpServerInit::~TcpServerInit()
{
}

void TcpServerInit::Listen(const std::string& host,uint16_t port, int backlog)
{
    if(_socket==-1)
    {
        cout<<"create tcp server socket failed"<<endl;
    }

    _host = host;
    _port = port;

    Socket::NativeAddress serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));  

    serverAddress.sin_family = AF_INET;  
    serverAddress.sin_addr.s_addr = inet_addr(_host.c_str());  
    serverAddress.sin_port = htons(_port);  

    int err = bind(_socket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));  
    if ( err == -1 ) {
        cout<<"server bind failed"<<endl;
    }

    err = listen(_socket, backlog);  
    if ( err == -1 ) {
        cout<<"server listen failed"<<endl;
    }
}

std::shared_ptr<TcpConnection> TcpServerInit::Accept()
{
    Socket::NativeAddress clientAddress;
    socklen_t addressLength = sizeof(clientAddress);
    Socket::NativeSocket clientFd = accept(_socket,(struct sockaddr *)& clientAddress,&addressLength);

    // 这里make_shared就是取代new的方法,帮助我们构造对象并放到智能指针中
    std::shared_ptr<TcpConnection> conn = std::make_shared<TcpConnection>(clientFd);
    conn->SetAddress(clientAddress);

    return conn;
}
