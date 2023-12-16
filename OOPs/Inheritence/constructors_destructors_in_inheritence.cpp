#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Constructors and class initialization:
- The Base part of the Derived class Must be initialized Before the  Derived class is initalized.

Destructors are invoked in the reverse order as constructors.
-The Derived part of the Derived class Must be destroyed before the Base class destructor is invoked.
-Each destructor should free resources allocated in it's own constructors.

Derived class doesn't inherit:
- Base class constructors.
- Base class destructor.
- Base class overloaded assignment operators
- Base class friend functions.
*/
class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << " base No args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base int overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
private:
    int double_value;

public:
    Derived() : double_value{0} { cout << " Derived No args constructor" << endl; }
    Derived(int x) : double_value{x * 2} { cout << "Derived int overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main()
{
    {
        Base b;
    }
    {

        Base b1{100};
    }

    {

        Derived d;
    }
    {

        Derived d1{2000};
    }

    return 0;
}