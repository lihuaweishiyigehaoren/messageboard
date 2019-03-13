/*
*Auther: HuaWeiLi
*Date: 2019.03.02
*FileDesc: accept() 返回的连接
*/
#include "TcpStream.h"
#include <iostream>
using namespace std;

TcpStream::TcpStream(Socket::NativeSocket socket) :
    Socket(socket)
{
}

TcpStream::~TcpStream()
{
}

ssize_t TcpStream::Send(const void* buffer,size_t len)
{
    // reinterpret_cast主要是将数据从一种类型转换为另一种类型，转换前后没有数位损失
    const char* byteBuffer = reinterpret_cast<const char*>(buffer);
    
    ssize_t err = send(_socket,byteBuffer,len,0);
    if(err==-1)
    {
        cout<<"socket send error"<<endl;
    }
    
    if(err <0)
    {
        cout<<"unknow error"<<endl;
    }

    // err>0 返回的是发送或接受的字节数 
    size_t sentBytes = static_cast<size_t>(err);
    size_t totalSend = sentBytes;

    while(sentBytes < len && sentBytes !=0 )
    {
        byteBuffer += sentBytes;

        len -= sentBytes;
        err = send(_socket, byteBuffer, len, 0);
        if ( err == -1 ) {
            cout<<"socket send failed"<<endl;
        }

        if ( err < 0 ) {
            cout<<"unknow error"<<endl;
        }

        sentBytes = static_cast<size_t>(err);
        totalSend += sentBytes;
    }
    
    return totalSend;

}

ssize_t TcpStream::Receive(void* buffer,size_t len)
{
    ssize_t err = recv(_socket,buffer,len,0);
    if(err == -1)
    {
        cout<<"socket receive failed"<<endl;
    }

    return err;
}

ssize_t TcpStream::Write(const void * buffer,size_t len)
{
    return Send(buffer,len);
}

ssize_t TcpStream::Read(void * buffer,size_t len)
{
    return Receive(buffer,len);
}