#include<iostream>
using namespace std;
class A{
    int x;
    public:
    A(int x)
    {
        this->x = x;
    }
    friend class sub;
};  

class B{
    int x;
    public:
    B(int x)
    {
        this->x = x;
    }
    friend class sub;
};

class sub{
    public:
    void max(A &obj1 , B &obj2)
    {
        if(obj1.x > obj2.x)
            cout<<"MAX: "<<obj1.x;
        else
            cout<<"MAX: "<<obj2.x;
    }
};

int main()
{
    A a(10);
    B b(5);
    sub s;
    s.max(a,b);
    return 0;
}