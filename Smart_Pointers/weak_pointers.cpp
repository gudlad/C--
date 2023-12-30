#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*

! Weak Pointers::
- Provides non-owning "weak" reference.
- Points to an object of type T on the heap but
- It doesn't participate in the owning relationship
- Always created from a shared ptr
- Doesn't increment or decrement reference use count
- Used to prevent strong reference cycles which could prevent objects from being deleted.
- we can use weak pointers to temporaily reference to a set of objects for examples while iterating through a list.

*/

//! Need of Weak pointers and and problem with shared pointers
//! To avoid strong circular reference ex:
class B;

class A
{
private:
    std::shared_ptr<B> ptr;

public:
    A(/* args */);
    ~A();
    void set_B(std::shared_ptr<B> &obj)
    {
        ptr = obj;
    }
};

A::A(/* args */)
{
    cout << "A constructor" << endl;
}

A::~A()
{
    cout << "A destructor" << endl;
}

class B
{
private:
    std::shared_ptr<A> ptr;

public:
    B(/* args */);
    ~B();
    void set_A(std::shared_ptr<A> &obj)
    {
        ptr = obj;
    }
};

B::B(/* args */)
{
    cout << "B constructor" << endl;
}

B::~B()
{
    cout << "B destructor" << endl;
}

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    return 0;
    // Here variables a and b are destroyed and not the memory on the heap as the use count will not be zero
    // Ultimately leading to memory leak due to the shared ownership.
}