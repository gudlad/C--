#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Account
{
public:
    virtual void withdraw()
    {
        cout << "withdraw from Account" << endl;
    }
    virtual ~Account() {}
};

class Savings_Account : public Account
{
public:
    virtual void withdraw()
    {
        cout << "withdraw from Savings Account" << endl;
    }
    virtual ~Savings_Account() {}
};

class Trust_Account : public Savings_Account
{
public:
    virtual void withdraw()
    {
        cout << "withdraw from Trust Account" << endl;
    }
    virtual ~Trust_Account() {}
};

void do_withdraw(Account &ac)
{
    ac.withdraw();
}
/*

!Base call references
- we can also use Base class references with dynamic polymorphism.
- useful when we pass objects to functions that except a Base class reference.

*/

int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw();

    Savings_Account sa;
    Account &sref = sa;
    sref.withdraw();

    Trust_Account ta;
    Account &tref = ta;
    tref.withdraw();

    do_withdraw(a);
    do_withdraw(sa);
    do_withdraw(ta);

    return 0;
}