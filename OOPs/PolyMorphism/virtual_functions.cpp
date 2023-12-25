#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*

!Virtual functions
- Redefined functions are bound statically
- Overridden functions are bound dynamically
- virtual functions are overridden
- Allows us to treat all objects generally as objects of the Base class.
- Override the function in the derived classes
- virtual keyword not required but it is best practice
- If you don't provide an overriden version it is inherited from it's base class

*/
class Base
{
public:
    virtual void say_hello() const
    {
        std::cout << "Hello- I'm a Base class Object" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void say_hello() const
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
    Base b;
    Derived d;
    greeting(b);
    greeting(d);
    Base *ptr = new Derived{};
    ptr->say_hello();

    return 0;
}
