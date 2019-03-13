/*
*Auther: HuaWeiLi
*Date: 2019.03.13
*FileDesc: exception class
*/
#include "SocketException.h"
#include <string>

SocketException::SocketException(int code, const std::string& message) :
    _code(code), _message(message) {
    _what = "Error " + std::to_string(_code) + ": " + _message;
}

const char* SocketException::what() const noexcept {
    return _what.c_str();
}

int SocketException::GetCode() const {
    return _code;
}

const std::string& SocketException::GetMessage() const {
    return _message;
}
