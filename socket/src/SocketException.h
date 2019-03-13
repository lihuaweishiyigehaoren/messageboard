#include <exception>
#include <string>

class SocketException : public std::exception {
public:
    SocketException(int code, const std::string& message);

    const char* what() const noexcept;

    int GetCode() const;
    const std::string& GetMessage() const;

private:
    int _code;
    std::string _message;
    std::string _what;
};