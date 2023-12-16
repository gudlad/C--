#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*

Controlling the calling of Base class constructors
-We can control which Base class constructor is used during initialization fo Derived class.
-We can invoke whichever Base class constructor we wish in the initialization list of the Derived class.

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
    Derived() : Base{}, double_value{0}
    {
        cout << " Derived No args constructor" << endl;
    }

    Derived(int x) : Base{x}, double_value{x * 2}
    {
        cout << "Derived int overloaded constructor" << endl;
    }

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    Derived d;
    return 0;
}