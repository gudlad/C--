#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello- I'm a Base class Object" << endl;
    }
};

class Derived : public Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello- I'm a Derived class Object" << endl;
    }
};

void greeting(const Base &obj)
{
    obj.say_hello();
}

int main()
{
    // static bindings.
    Base b;
    Derived d;
    greeting(b);
    greeting(d); // problem with stating binding calls Base say hello instead of Derived.

    Base *ptr = new Derived{};
    ptr->say_hello(); // problem: ptr is a pointer to Base so it calls Base's method.

    //! to overcome this we have to use virtual keyword which tells the compiler to do the binding during runtime rather than compile time
    return 0;
}

//! To achieve dynamic binding or runtime polymorphism we must have::
//  Inheritance
//  Base class  pointer or Base class   reference.
//  virtual functions.