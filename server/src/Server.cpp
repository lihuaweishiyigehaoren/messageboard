/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "Server.h"

Server::Server(const std::string& host,uint16_t port) :
    _host(host),_port(port),_toExit(false)
{
}

Server::~Server()
{
}

void Server::start()
{
    _tcpServer.Listen(_host,_port);
    cout<<"Server is listening on :"<<_host<<":"<<_port<<endl;

    while(!_toExit){
        std::shared_ptr<TcpConnection> conn = _tcpServer.Accept();
        cout<<"accept cliengt from:"<<conn->GegtHost()<<":"<<conn->GetPort()<<endl;
    }
    
}