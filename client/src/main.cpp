/*
*Auther: HuaWeiLi
*Date: 2019.03.12
*FileDesc: a main Function of sever
*/

#include <iostream>
#include "Client.h"
using namespace std;

int main()
{
    Client client("127.0.0.1",8000);
    client.start();
    
    return 0;
}