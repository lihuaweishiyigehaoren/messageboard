#include "TcpStream.h"
#include <string>
using namespace std;

class TcpConnection : public TcpStream
{
public:
    TcpConnection(Socket::NativeSocket socket);
    ~TcpConnection();

    const std::string& GegtHost() const;
    uint16_t GetPort() const;
    void SetAddress(const Socket::NativeAddress& address);

private:
    std::string _host;
    uint16_t _port;
};

