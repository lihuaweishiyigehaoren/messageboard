#include "Socket.h"

class TcpStream : Socket
{
private:
    /* data */
public:
    TcpStream(Socket::NativeSocket socket);
    ~TcpStream();

    // size_t 适于计量内存中可容纳的数据项目个数的无符号整数类型 ssize_t便于移植
    ssize_t send(const void* buffer,size_t len);
    ssize_t Receive(void* buffer,size_t len);

    ssize_t write(const void * buffer,size_t len);
    ssize_t read(void * buffer,size_t len);
};
