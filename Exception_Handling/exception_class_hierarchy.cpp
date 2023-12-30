#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

/*

! C++ standard library exception class hierarchy
- std::exception is the base class
- all subclasses implement what() virtual function which returns c style string char*
- we can define our own user-defined exception classes.
- the noexcept keyword tells the compiler that the method or constructor will not throw any exception, by mistake if we throw exception pgm will terminate
- the destructors are by default no except.

*/

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char *what() const noexcept
    {
        return "Illegal Balance Exception";
    }
};

class Account
{
public:
    double balance{0};
    Account(double balance) : balance{balance}
    {
        if (balance < 0)
            throw IllegalBalanceException();
    }
};

int main()
{
    try
    {
        std::unique_ptr<Account> ac = std::make_unique<Account>(-100);
    }
    catch (const IllegalBalanceException &err)
    {
        std::cerr << err.what() << endl;
    }
    cout << "Exiting>.." << endl;

    return 0;
}