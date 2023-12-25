#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

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
    // better way to initialize the shared pointers.
    std::shared_ptr<int> p1 = std::make_shared<int>(100); // use count 1
    cout << p1.use_count() << endl;
    std::shared_ptr<int> p2{p1}; // use count 2
    cout << p2.use_count() << endl;
    std::shared_ptr<int> p3; // use count 3
    p3 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << p3.use_count() << endl;
    cout << "-------------------------------------------------" << endl;
    // use make_shared -> it's more efficient.
    // all 3 pointers point to the same object on the heap.
    // when the use_count becomes 0 the heap object is deallocated.
    {
        std::shared_ptr<Account> acc1 = std::make_shared<Account>("Larry");
        std::shared_ptr<Account> acc2 = std::make_shared<Account>("Moe");
        std::shared_ptr<Account> acc3 = std::make_shared<Account>("Curly");

        std::vector<std::shared_ptr<Account>> accounts;
        accounts.push_back(acc1);
        accounts.push_back(acc2);
        accounts.push_back(acc3);

        for (const auto &acc : accounts)
            cout << acc.use_count() << endl;
    }
}