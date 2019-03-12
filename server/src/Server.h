#include <cstdint>
#include <vector>

using namespace std;
#include <string>
#include "TcpServerInit.h"

class Server
{
public:
    
    // &-如果不传引用进来字符串可能会被复制两次.划不来
    Server(const std::string& host,uint16_t port);
    ~Server();

    void set_host(std::string host)
    {
        _host = host;
    }

    void set_port(uint16_t port)
    {
        _port = port;
    }

    void start();

    
private:
    std::string _host;
    uint16_t _port;
    TcpServerInit _tcpServer;
};

