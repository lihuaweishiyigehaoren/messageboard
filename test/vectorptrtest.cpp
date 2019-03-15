/*
*该文件用于测试一个智能指针向量,智能指针没了之后会怎么样
*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Person
{
public:
    Person() :
    _age(10)
    {

    }

    ~Person()
    {

    }

    void GetAge()
    {
        cout<<_age<<"   ";
    }

private:
    int _age;
};

int main()
{
    std::vector<shared_ptr<Person>> persons;

    for(int i = 0;i<5;i++)
    {
        shared_ptr<Person> person = make_shared<Person>();

        persons.push_back(person);
    }

    for(shared_ptr<Person> person : persons)
    {
        person->GetAge();
    }

    cout<<endl;

    return 0;
}