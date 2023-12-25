#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
! C++ final specifier
- when used at class level
    prevents a class from being derived from
- when used at the method level
    prevents virtual method from being overriden in derived class.

*/

class Base
{
public:
    virtual void say_hello() const final
    {
        std::cout << "Hello- I'm a Base class Object" << endl;
    }
    virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived final : public Base
{
public:
    // here can't override the say_hello() function.
    // also not in following subclass.
    virtual ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

class Derived2 : public Derived // Derived is final so not able to inherit.
{
public:
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
    return 0;
}
