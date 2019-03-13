/*
*Auther: HuaWeiLi
*Date: 2019.03.13
*FileDesc: message class
*/
#include "Message.h"

Message::Message() :
    _version(1),_type(Message::Type::Invalid)
{

}

Message::~Message()
{

}

int32_t Message::GetVersion() const {
    return _version;
}

int32_t Message::GetType() const {
    return _type;
}

const std::string& Message::GetContent() const {
    return _content;
}

void Message::SetVersion(int32_t version) {
    _version = version;
}

void Message::SetType(int32_t type) {
    _type = type;
}

void Message::SetContent(const std::string& content) {
    _content = content;
}

void  Message::Read(TcpStream *stream)
{
    int32_t size;
    stream->Read(&_version,sizeof(_version));
    stream->Read(&_type,sizeof(_type));
    stream->Read(&size,sizeof(size));

    if(size)
    {
        char * buffer = new char[size];
        stream->Read(buffer,size*sizeof(char));
        _content = std::string(buffer,size);

        delete [] buffer;
    }
    
}

void  Message::Write(TcpStream *stream)
{
    int32_t size = _content.size();

    stream->Write(&_version, sizeof(_version));
    stream->Write(&_type, sizeof(_type));
    stream->Write(&size, sizeof(size));

    if ( size ) {
        stream->Write(_content.c_str(), size * sizeof(char));
    }
}