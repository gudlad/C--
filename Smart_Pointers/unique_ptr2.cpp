#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*
! Unique Pointer:
- It is unique - there can be one unique_ptr<T> pointing to the object on the heap.
- owns what it points to
- can't be assigned or copied
- can be moved
- when the pointer is destroyed , what it points to is automatically destroyed.
*/

class Account
{
private:
    std::string name;
    double balance;

public:
    Account(std::string name, double balance);
    ~Account();
};

Account::Account(std::string name, double balance)
{
    this->name = name;
    this->balance = balance;
}

Account::~Account()
{
}

int main()
{
    //? one way of initializing unique pointers.
    std::unique_ptr<int> p1{new int(100)};

    //? another better way of initializing unique pointers.
    //? using the make_unique method which takes the inputs which can be passed managed objects constructors.
    std::unique_ptr<int> ptr1 = std::make_unique<int>(100);

    std::unique_ptr<Account> ptr2 = std::make_unique<Account>("Hero", 5000);

    std::unique_ptr<Account> ptr2{new Account{"Ram", 5000}};

    auto ptr3 = std::make_unique<Account>("Villain", 1000);

    std::unique_ptr<Account> ptr5;
    //  ptr5 = ptr1; //! error can't copy unique pointer
    ptr5 = std::move(ptr2); //? moves the ownership of Account obj to ptr5
}