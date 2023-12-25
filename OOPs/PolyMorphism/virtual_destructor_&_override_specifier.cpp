#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*

!Virtual destructors.
- if a class has virtual functions
- always provide a public virtual destructor, otherwise it will cause serious problems.
- it only calls base call destructor and will not cause derived call destructor leading to memory leaks.
- if base class destructor is virtual then all derived class destructors are also virtual

!Override specifier
- c++11 provides override specifier to ensure overriding.

*/

class Base
{
public:
    virtual void say_hello() const
    {
        std::cout << "Hello- I'm a Base class Object" << endl;
    }
    virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void say_hello() const override
    {
        std::cout << "Hello- I'm a Derived class Object" << endl;
    }
    virtual ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

class Derived2 : public Derived
{
public:
    virtual void say_hello() const override
    {
        std::cout << "Hello- I'm a Derived2 class Object" << endl;
    }
    virtual ~Derived2()
    {
        cout << "Derived2 destructor" << endl;
    }
};

void greeting(Base *ptr)
{
    ptr->say_hello();
}

int main()
{
    {
        Base *p1 = new Base{};
        greeting(p1);
        delete p1;
    }
    cout << "------------------" << endl;
    {
        Base *p2 = new Derived{};
        greeting(p2);
        delete p2;
    }
    cout << "------------------" << endl;

    {
        Base *p3 = new Derived2{};
        greeting(p3);
        delete p3;
    }
    return 0;
}
