#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*

! strong circular reference solutions using weak pointers.
- make one of the pointers non-owning or weak
- now heap storage is deallocated properly.

*/

class B;

class A
{
private:
    std::shared_ptr<B> ptr; // owning pointer.

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
{ // non owning pointer.
private:
    std::weak_ptr<A> ptr; //!  use weak pointer to prevent the circular reference problem.

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
    cout << a.use_count() << endl;
    cout << b.use_count() << endl;
    a->set_B(b);
    b->set_A(a);
    cout << a.use_count() << endl;
    cout << b.use_count() << endl;
    return 0;
}