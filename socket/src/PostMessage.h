/*
*Auther: HuaWeiLi
*Date: 2019.03.14
*FileDesc: 
*/

#pragma once

#include <string>

class PostMessage
{
public:

    static PostMessage FromMessage(const std::string& message)
    {
        size_t pos = message.find("\n");
        if(pos == std::string::npos)
        {
            return PostMessage();
        }

        std::string title = message.substr(0,pos);
        std::string content = message.substr(pos);

        return PostMessage(title,content);
    }

    PostMessage() : 
    _valid(false)
    {
    }

    PostMessage(const std::string& title,const std::string& content) :
    _valid(true),_title(title),_content(content)
    {

    }

    ~PostMessage()
    {
        
    }

    const std::string ToMessage() const
    {
        return _title + "\n" +_content;
    }

    bool isVaild() const
    {
        return _valid;
    }

    void SetValid(bool valid) {
        _valid = valid;
    }

    const std::string& GetTitle() const {
        return _title;
    }

    void SetTile(const std::string& title) {
        _title = title;
    }

    const std::string& GetContent() const {
        return _content;
    }

    void SetContent(const std::string& content) {
        _content = content;
    }

private:
    bool _valid;
    std::string _title;
    std::string _content;

};
