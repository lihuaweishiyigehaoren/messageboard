/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "TcpServerInit.h"
#include <cstring>


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
    memset(&serverAddress,0,sizeof(serverAddress));

    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(_host.c_str());  
    serverAddress.sin_port = htons(_port);  

    if(bind(_socket,(struct sockaddr *)&serverAddress,sizeof(serverAddress))==-1)
    {
        cout<<"server bind socket failed"<<endl;
    }

    if(listen(_socket,backlog)==-1)
    {
        cout<<"server listen socket failed"<<endl;
    }

}
