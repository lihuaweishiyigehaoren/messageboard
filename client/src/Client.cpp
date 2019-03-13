/*
*Auther: HuaWeiLi
*Date: 2019.03.12
*FileDesc: a client start progrem
*/
#include "Client.h"
#include "SocketException.h"
#include "Message.h"
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
    try
    {
        _tcpClient.Connect(_host,_port);
        cout<<"client is connected to:"<<_host<<":"<<_port<<endl;

        while(!_toExit){
            string commandName;
            cout<<">> ";
            getline(cin,commandName);

            if(commandName == "shutdown")
            {
                DoShutDown();
                Exit();
            }
        }
        
    }
    catch(const SocketException& e)
    {
        std::cerr << e.what() << endl;
    }
    
    
}

void Client::Exit()
{
    _toExit = true;
}

void Client::DoShutDown()
{
    Message message;
    message.SetType(Message::Type::ShutdownRequest);

    message.Write(&_tcpClient);
}

void Client::DoPost()
{

}

void Client::DoGet()
{

}

void Client::InvalidCommand(int type)
{

}

void Client::InvalidCommand(const std::string & commandName)
{

}
