#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

/*
public inheritance provides the IS-A relationship like Savings Account is an Account.
composition provides HAS-A relationship like Person has an Account.
*/

class Account
{
public:
    double balance;
    std::string name;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    ~Account();
};

Account::Account() : balance{0.0}, name{"An account"} {}
Account::~Account() {}
void Account::deposit(double amount) { cout << "Ac depo called.." << endl; }
void Account::withdraw(double amount) { cout << "Ac withdrw called.." << endl; }

class Savings_Account : public Account
{
public:
    double int_rate{};
    void deposit(double amount);
    void withdraw(double amount);
    Savings_Account();
    ~Savings_Account();
};

Savings_Account::Savings_Account() : int_rate{3.0} {}
Savings_Account::~Savings_Account() {}
void Savings_Account::deposit(double amount) { cout << "Sav Ac depo called.." << endl; }
void Savings_Account::withdraw(double amount) { cout << "Sav Ac withdrw called.." << endl; }

int main()
{
    Account acc{};
    acc.deposit(2000);
    acc.withdraw(1000);

    Savings_Account *sa{nullptr};
    sa = new Savings_Account();

    sa->deposit(2000);
    sa->withdraw(500);

    return 0;
}