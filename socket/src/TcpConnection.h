#include "TcpStream.h"
#include <string>
using namespace std;

class TcpConnection : TcpStream
{
public:
    TcpConnection(/* args */);
    ~TcpConnection();

    const std::string& GegtHost() const;
    uint16_t GetPort() const;
    // void SetAddress(const Socket::NativeAddress& address);

private:
    std::string _host;
    uint16_t _port;

};

