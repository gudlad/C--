#include <iostream>

using std::cin;
using std::cout;
using std::endl;
/*

This Pointer:
- Contains the address of the object- so it's pointer to the object.
- can only be used in class scope
- all members access is done via the "this" pointer
- uses:
-> To access data members and methods.
-> To determine if two objects are the same.
-> Can be dereferenced (*this) to yield the current object.

*/
class Account
{
    int balance{0};

public:
    void set_balance(int balance)
    {
        this->balance = balance;
    }
    /*
     void set_balance(int bal)
    {
        balance = bal;  //! this-> balance= bal; according to compiler.
    }
    */
    void compare_balance(Account &rhs)
    {
        if (this == &rhs)
        {
            cout << "same object is compared to itself" << endl;
            return;
        }
        if (this->balance > rhs.balance)
            cout << "account1 balance is greater" << endl;
        else
            cout << "account2 balance is greater" << endl;
    }
};
int main()
{
    Account a1;
    a1.set_balance(3000);
    Account a2;
    a2.set_balance(5000);
    a1.compare_balance(a2);
    a1.compare_balance(a1);
    return 0;
}