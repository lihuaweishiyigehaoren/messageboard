/*
*Auther: HuaWeiLi
*Date: 2019.03.12
*FileDesc: a client start progrem
*/
#include "Client.h"
#include "SocketException.h"
#include "Message.h"
#include "PostMessage.h"
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
            else if(commandName == "exit")
            {
                Exit();
            }
            else if(commandName == "post")
            {
                DoPost();
            }
            else if(commandName == "get")
            {
                DoGet();
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
    cout<<"title?:";
    string title;
    getline(cin,title);

    cout<<"Content?:";
    string content;
    getline(cin,content);

    PostMessage newPost(title,content);
    Message message;
    message.SetType(Message::Type::PostRequest);
    message.SetContent(newPost.ToMessage());

    message.Write(&_tcpClient);// 投递消息到服务器
}

void Client::DoGet()
{
    Message message;
    message.SetType(Message::Type::GetRequest);
    message.Write(&_tcpClient);

    Message response;
    response.Read(&_tcpClient);

    if(response.GetType() != Message::Type::GetResponse)
    {
        InvalidCommand(response.GetType());
    }

    cout<<"got latest post"<<endl;
    string responseContent = response.GetContent();
    if(responseContent.empty())
    {
        std::cerr<<"there is no any posts now"<<endl;
        return;
    }

    PostMessage latestPost = PostMessage::FromMessage(responseContent);
    if(!latestPost.isVaild())
    {
        std::cerr<<"Response format of GET is invalid"<<endl;
        return;
    }

    cout<<"Title :"<<latestPost.GetTitle()<<endl;
    cout<<"Content:"<<latestPost.GetContent()<<endl;

}

void Client::InvalidCommand(int type)
{
    std::cerr<<"Command"<<type<<"is invalid"<<endl;
}

void Client::InvalidCommand(const std::string & commandName)
{
    std::cerr<<"Command"<<commandName<<"is invalid"<<endl;
}
