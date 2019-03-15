/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "Server.h"
#include "SocketException.h"
#include <sys/types.h>
#include <unistd.h>


Server::Server(const std::string& host,uint16_t port) :
    _host(host),_port(port),_toExit(false)
{

}

Server::~Server()
{

}

void Server::start()
{
    try
    {
        _tcpServer.Listen(_host,_port);
        cout<<"Server is listening on :"<<_host<<":"<<_port<<endl;

        // 不断的获取客户端连接请求
        while(!_toExit)
        {
            std::shared_ptr<TcpConnection> conn = _tcpServer.Accept();
            cout<<"accept client from:"<<conn->GegtHost()<<":"<<conn->GetPort()<<endl;

            // _clientConns.push_back(conn);
            // for(shared_ptr<TcpConnection> conn : _clientConns)
            // {
            //     ProcessClientRequ(conn.get());
            // }

            pid_t pid = fork();
            if(!pid)
            {
                ProcessClientRequ(conn.get());
                break;
            }
        }
    }
    catch(const SocketException& e)
    {
        std::cerr << e.what() <<endl;
    }

}

Message Server::OnPost(const Message& message)
{
    cout<<"post"<<endl;

    Message response;
    response.SetType(Message::Type::PostResponse);

    PostMessage newPost = PostMessage::FromMessage(message.GetContent());
    if(!newPost.isVaild())
    {
        std::cerr<<"the format of new post is invalid"<<endl;
        response.SetContent("error");

        return response;
    }

    _postmessages.push_back(newPost);
    response.SetContent("ok");

    return response;

    
}

Message Server::OnGet(const Message& message)
{
    cout<<"get"<<endl;

    Message response;
    response.SetType(Message::Type::GetResponse);

    if(!_postmessages.size())
    {
        return response;
    }

    PostMessage latesPost = _postmessages.back();
    response.SetContent(latesPost.ToMessage());
    cout<<latesPost.ToMessage();

    return response;
}

void Server::ShutDown()
{
    cout<<"shut down server by client"<<endl;
    _toExit = true;
}

void Server::InvalidMessage(int type)
{
    cout<<"command"<<type<<"is invalid"<<endl;
}

void Server::ProcessClientRequ(TcpConnection * conn)
{
    // 一直等待客户端发送命令
    bool clientAlived = true;
    while(clientAlived)
    {
        Message message;
        message.Read(conn);
        int messageType = message.GetType();
        switch ( messageType ) {
        case Message::Type::Invalid:
            InvalidMessage(messageType);
            clientAlived = false;
            break;
        case Message::Type::ShutdownRequest:
            ShutDown();
            clientAlived = false;
            break;
        case Message::Type::PostRequest: {
            Message response = OnPost(message);
            response.Write(conn);
            break;
        }
        case Message::Type::GetRequest: {
            Message response = OnGet(message);
            response.Write(conn);
            break;
        }
        default:
            InvalidMessage(messageType);
            clientAlived = false;
            break;
        }
    }
    cout<<"client disconnected:"<<conn->GegtHost()<<":"<<conn->GetPort()<<endl;
}
