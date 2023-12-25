#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
!Shared Pointer::
- Provides shared ownership of heap objects.
- it's not unique there can be many shared pointers pointing to the same object on the heap.
- can be assigned and copied.
- can be moved
- when the use count is zero, the managed object on the heap is destroyed.
 */

class Account
{
private:
    std::string name;

public:
    Account(std::string name);
    ~Account();
    void deposit(int a);
    void withdraw(int b);
};

void Account::deposit(int a)
{
    cout << "Deposited amount" << endl;
}

void Account::withdraw(int b)
{
    cout << "Withdraw amount" << endl;
}

Account::Account(std::string name)
{
    this->name = name;
}

Account::~Account()
{
}

int main()
{
    // shared pointer method - use count
    // returns the number of shared_ptr objects managing the heap object.
    std::shared_ptr<int> p1{new int{100}};
    cout << p1.use_count() << endl; //! 1 -> p1 is the shared obj referencing to the value on the heap.

    std::shared_ptr<int> p2{p1};    //! shared-ownership, now p2 reference to the same heap object as p1.
    cout << p1.use_count() << endl; // 2
    cout << p2.use_count() << endl; // 2

    p1.reset();                     //! decrements the use_count; p1 is nulled out
    cout << p1.use_count() << endl; // 0
    cout << p2.use_count() << endl; // 1
    return 0;

    // shared ptr - user defined classes
    std::shared_ptr<Account> p3{new Account("Larry")};
    cout << p3 << endl;
    p3->deposit(500);
    p3->withdraw(500);

    // shared ptr and vector
    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr{new int{100}};

    vec.push_back(ptr); //? OK - COPY Is Allowed
    std::cout << ptr.use_count() << endl;
}