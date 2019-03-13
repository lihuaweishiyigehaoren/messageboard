#include "TcpClientInit.h"

class Client
{
public:
    Client(const std::string &host,uint16_t port);
    ~Client();

    void start();

private:
    void Exit();
    void DoShutDown();
    void DoPost();
    void DoGet();
    void InvalidCommand(int type);
    void InvalidCommand(const std::string & commandName);

private:
    TcpClientInit _tcpClient;
    std::string _host;
    uint16_t _port;
    bool _toExit;

};
