#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Copy/Move constructors and overloaded operator=
- Not inherited from the Base class
- we can invoke the Base class versions from the Derived class

!Note:
- Often we don't need to provide our own copy,move, assignment operators.
-If you don't not define them in Derived
    then compiler will create them and automatically and call the base class's version

-If you provide Derived versions
    then you must invoke the Base versions explicitly.

- Be careful with raw pointers
    especially if Base and Derived each have raw pointers
    provide them with deep copy semantics.

*/

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << " base No args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base int overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }

    // copy constructor
    Base(const Base &other) : value(other.value)
    {
        cout << "Base copy constructor" << endl;
    }
    // the move-constructor also works the same ( if raw pointers,dynamic memory present only not useful here)

    // assignment operator
    Base &operator=(const Base &rhs)
    {
        cout << "base copy assignment" << endl;
        if (this == &rhs)
            return *this;
        this->value = rhs.value;
        return *this;
    }
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

    // copy constructor
    Derived(const Derived &other) : Base(other), double_value(other.double_value)
    {
        cout << "Derived copy constructor" << endl;
    }
    // the move-constructor also works the same ( if raw pointers,dynamic memory present only not useful here)

    // copy assignment
    Derived &operator=(const Derived &rhs)
    {
        cout << "derived copy assignment" << endl;
        if (this != &rhs)
        {
            Base::operator=(rhs);            // assign the Base part.
            double_value = rhs.double_value; // assign Derived part.
        }
        return *this;
    }
};

int main()
{
    {
        Base b{100};
        Base b1{b};
        b = b1;
    }
    cout << "---------------------------" << endl;
    {
        Derived d{2000};
        Derived d1{d};
        d = d1;
    }
    return 0;
}