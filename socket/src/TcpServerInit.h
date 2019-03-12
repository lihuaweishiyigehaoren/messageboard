#include <string>
#include <iostream>
#include <memory>
#include "TcpConnection.h"
using namespace std;
class TcpServerInit : public Socket
{
public:
    TcpServerInit();
    virtual ~TcpServerInit();
    void Listen(const std::string& host,uint16_t port, int backlog=0);
    std::shared_ptr<TcpConnection> Accept();

private:
    std::string _host;
    uint16_t _port;
};
