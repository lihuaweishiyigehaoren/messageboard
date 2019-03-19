/*
*Auther: HuaWeiLi
*Date: 2019.03.15
*FileDesc: 进程间通信,命名管道
*/

#include "NamedPiped.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <exception>
using namespace std;

#define PIPE_BUF 255

NamedPiped::NamedPiped(std::string& path,NamedPiped::OpenMode mode) :
    _le(-1),_mode(mode)
{
    int openMode = 0;
    if(_mode == OpenMode::ReadOnly)
    {
        openMode = O_RDONLY;
    }
    else if(_mode == OpenMode::WriteOnly)
    {
        openMode = O_WRONLY;
    }

    if(access(path.c_str(),F_OK)==-1)
    {
        int res = mkfifo(path.c_str(),0777);
        if(res != 0)
        {
            std::cerr<<"无法创建管道文件"<<std::endl;
        }
    }

    _file = open(path.c_str(),openMode);
    
}

NamedPiped::~NamedPiped()
{
    if(_le && _le!=-1)
    {
        close(_le);
    }
}

/*
*desc:sizeToRead-用户指定需要读取的字节数
*每次从管道里至多读取PIPE_BUF字节的数据,然后将数据拼接到最后的读取结果上
*直到最后读取的字节数与用户指定的字节数相等为止
*/
const std::string NamedPiped::read(int sizeToRead)
{
    checkFileOpen();
    checkOpenMode(OpenMode::ReadOnly);

    int readBytes = 0;
    std::string content;
    do
    {
        char buffer[PIPE_BUF];

        int bytesToRead = 0;
        if(readBytes + PIPE_BUF < sizeToRead)
        {
            bytesToRead = PIPE_BUF;
        }
        else
        {
            bytesToRead = sizeToRead-readBytes;
        }

        if(::read(_file,buffer,bytesToRead)==-1)
        {
            cout<<"read buffer failed"<<endl;
        }

        readBytes += bytesToRead;
        content += std::string(buffer,bytesToRead);

    }while(readBytes<sizeToRead);

    return content;
}

void NamedPiped::write(const std::string& content)
{
    checkFileOpen();
    checkOpenMode(OpenMode::WriteOnly);

    int writtenBytes = ::write(_file,content.c_str(),content.size());
    if(writtenBytes == -1)
    {
        cout<<"write failed"<<endl;
    }
}

void NamedPiped::checkFileOpen()
{
    if(_file==-1)
    {
        cout<<"fifo failed"<<endl;
    }
}

void NamedPiped::checkOpenMode(OpenMode mode)
{
    if(_mode != mode)
    {
        cout<<"open mode is not readonly"<<endl;
    }
}