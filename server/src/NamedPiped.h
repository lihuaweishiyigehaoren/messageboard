#include <string>

class NamedPiped
{
public:

    // 枚举类-读写模式
    enum class OpenMode
    {
        ReadOnly,
        WriteOnly
    };

    NamedPiped(std::string& path,NamedPiped::OpenMode mode);
    ~NamedPiped();

    const std::string read(int sizeToRead);
    void write(const std::string& content);

private:

    void checkFileOpen();
    void checkOpenMode(OpenMode mode);


private:
    int _le;
    NamedPiped::OpenMode _mode;
    int _file;
};

