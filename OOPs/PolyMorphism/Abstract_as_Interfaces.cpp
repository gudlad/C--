#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
!Using a class as an Interface:
- An abstract class that has only pure functions act as an Interface.
- These functions provide a general set of services to the user of the class
- Provide as public.
- Each subclass is free to implement these services as needed.
- Every service (method) must be implemented
- The service type information is strictly enforced.
!ex;
Suppose we want to be able to provide Printable support for any object we wish
without knowing it's implementation at compile time.

cout<< any_object << endl;

any_object must implement Printable Interface.

!.note.
Earlier in order to print the objects we used to overload the << operator in each class, which lead to lot of code duplication as friend function is not inheritable.
In this file we use Printable interface and print() function to reduce the code duplications for Account and it's child classes.

*/
class I_Printable //? usually done in .hpp or .cpp files.
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &rhs);

public:
    virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &rhs)
{
    rhs.print(os); // print is called based on dynamic polymorphism.
    return os;
}

class Account : public I_Printable
{
    // friend std::ostream &operator<<(std::ostream &os, const Account &ac);
public:
    virtual void withdraw(double amount)
    {
        cout << "In Account::withdraw" << endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Account Display......." << endl;
    }
    virtual ~Account() {}
};

class Savings_Account : public Account
{
    // friend std::ostream &operator<<(std::ostream &os, const Savings_Account &ac);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Savings Account::withdraw" << endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Savings Display......." << endl;
    }
    virtual ~Savings_Account() {}
};

class Checking_Account : public Account
{
    // friend std::ostream &operator<<(std::ostream &os, const Checking_Account &ac);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Checking Account::withdraw" << endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Checking Display......." << endl;
    }
    virtual ~Checking_Account() {}
};

class Trust_Account : public Account
{
    // friend std::ostream &operator<<(std::ostream &os, const Trust_Account &ac);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Checking Account::withdraw" << endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Trust Display......." << endl;
    }
    virtual ~Trust_Account() {}
};

// other classes also can now make use of printable interface
class Dog : public I_Printable
{
public:
    virtual void print(std::ostream &os) const override
    {
        os << "Woof woof......" << endl;
    }
};

int main()
{
    Dog *dog = new Dog();
    cout << *dog << endl;

    Account *p1 = new Account();
    cout << *p1 << endl;

    Account *p2 = new Savings_Account();
    cout << *p2 << endl;

    Account *p3 = new Trust_Account();
    cout << *p3 << endl;

    Account *p4 = new Checking_Account();
    cout << *p4 << endl;

    return 0;
}