#include <sys/socket.h>
#include "Socket.h"
#include <string>
#include <iostream>
using namespace std;
class TcpServerInit : Socket
{
public:
    TcpServerInit();
    ~TcpServerInit();

    void Listen(const std::string& host,uint16_t port, int backlog=0);
    // std::shared_ptr<> Accept();

private:
    std::string _host;
    uint16_t _port;
};
