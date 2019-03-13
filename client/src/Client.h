#include "TcpClientInit.h"

class Client
{
public:
    Client(const std::string &host,uint16_t port);
    ~Client();

    void start();

private:
    TcpClientInit _tcpClient;
    std::string _host;
    uint16_t _port;
    bool _toExit;

};
