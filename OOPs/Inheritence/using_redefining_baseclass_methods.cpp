#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*

!Using and redefining Base class methods
- Derived class can directly invoke Base class methods.
- Derived class can override or redefine Base class methods.
- useful in polymorphism.

*/

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

protected:
    double balance;

public:
    Account();
    Account(double amount);
    void deposit(double amount);
    void withdraw(double amount);
};

Account::Account() : Account{0.0} {}
Account::Account(double balance) : balance(balance){};
void Account::deposit(double amount) { balance += amount; }
void Account::withdraw(double amount)
{
    if (balance - amount >= 0)
        balance -= amount;
    else
        cout << "Insufficient balance" << endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "account balance: " << account.balance << endl;
    return os;
}

class Savings_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);

protected:
    double int_rate;

public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    void deposit(double amount);
    // withdraw() is inherited..
};

Savings_Account::Savings_Account(double balance, double int_rate) : Account(balance), int_rate(int_rate) {}
Savings_Account::Savings_Account() : Savings_Account(0.0, 0.0) {}
void Savings_Account::deposit(double amount)
{
    amount = amount + (amount * int_rate / 100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "SA balance :" << account.balance << " Interest rate: " << account.int_rate << endl;
    return os;
}
int main()
{
    Account a1{1000.0};
    cout << a1 << endl;
    a1.deposit(500.0);
    cout << a1 << endl;
    a1.withdraw(1000);
    cout << a1 << endl;
    cout << "------------" << endl;
    Savings_Account s1{1000, 5.0};
    cout << s1 << endl;
    s1.deposit(1000);
    cout << s1 << endl;
    s1.withdraw(1000);
    cout << s1 << endl;
    return 0;
}