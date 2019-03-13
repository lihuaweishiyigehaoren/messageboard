#include "TcpConnection.h"

class TcpClientInit : public TcpConnection
{
public:
    TcpClientInit();
    ~TcpClientInit();

    void Connect(const std::string& host,uint16_t port);

private:
    std::string _host;
    uint16_t _port;

};

