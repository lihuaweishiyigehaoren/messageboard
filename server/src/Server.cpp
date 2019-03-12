/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "Server.h"

Server::Server(const std::string& host,uint16_t port) :
    _host(host),_port(port)
{
}

Server::~Server()
{
}

void Server::start()
{
    _tcpServer.Listen(_host,_port);
}