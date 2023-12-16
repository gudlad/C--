#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

/*

Protected Access Specifier
- Accessible from the Base class itself
- Accessible from classes Derived from Base
- Not accessible by objects of Base or Derived.

*/
class Base
{
public:
    int a{0};

protected:
    int b{0};

private:
    int c{0};
};

class Derived : public Base
{
    //! Note:
    // friends of Derived have access to only what Derived has access to.

    // a will be public
    // b will be protected
    // c will not be accessible.

    void access_base_members()
    {
        a = 100; // Ok
        b = 200; // Ok
        // c = 1000; // not accessible.
    }
};

int main()
{
    //? Base member access from Base objects
    Base base;
    base.a = 100; // OK
    // base.b = 200; // Error
    // base.c = 300; // Error

    //? Base member access from Derived objects
    Derived d;
    d.a = 100; // Ok
    // d.b = 200; // Error
    // d.c = 300;  // Error
    return 0;
}