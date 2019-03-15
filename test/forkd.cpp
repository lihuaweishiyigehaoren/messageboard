#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main()
{

    // 父进程pid不为0 子进程拿到的永远都是0
    cout<<"hello"<<endl;

    pid_t pid = fork();

    cout<<"world"<<" "<<pid<<endl;
}