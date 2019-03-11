/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/
#include "TcpServerInit.h"


TcpServerInit::TcpServerInit() : Socket(socket(AF_INET,SOCK_STREAM,0))
{
}

TcpServerInit::~TcpServerInit()
{
}

void TcpServerInit::Listen(const std::string& host,uint16_t port, int backlog)
{
    if(_socket=-1)
    {
        cout<<"create tcp server socket failed"<<endl;
    }
}
