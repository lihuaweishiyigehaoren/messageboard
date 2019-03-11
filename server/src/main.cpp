/*
*Auther: HuaWeiLi
*Date: 2019.03.01
*FileDesc: a main Function of sever
*/

#include<iostream>
#include"Server.h"
using namespace std;

int main(){

    // cout<<"欢迎您进入网络编程之旅"<<endl;
    Server server("127.0.0.1",8000);

    return 0;
}