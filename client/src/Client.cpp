/*
*Auther: HuaWeiLi
*Date: 2019.03.12
*FileDesc: a client start progrem
*/
#include "Client.h"
#include <iostream>
using namespace std;

Client::Client(const std::string& host,uint16_t port) :
    _host(host),_port(port),_toExit(false)
{

}

Client::~Client()
{

}

void Client::start()
{
    _tcpClient.Connect(_host,_port);
    cout<<"client is connected to:"<<_host<<":"<<_port<<endl;
}
