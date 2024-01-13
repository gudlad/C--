#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

using std::cin;
using std::cout;
using std::endl;

void display(const std::vector<int> &vec)
{
    cout << "[";
    for (auto const &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
void test1()
{
    std::vector<int> vec{1, 2, 3, 4};

    auto it = vec.begin();

    cout << *it << endl;

    it++;
    cout << *it << endl;

    it += 2;
    cout << *it << endl;

    it -= 2;
    cout << *it << endl;

    it = vec.end() - 1; // point to last element.
    cout << *it << endl;
}

void test2()
{
    std::vector<int> vec{1, 2, 3, 4, 5};

    auto it = vec.begin();
    while (it != vec.end())
    {
        cout << *it << endl;
        it++;
    }

    /// change elements to zero
    it = vec.begin(); // reset to begin
    while (it != vec.end())
    {
        *it = 0;
        it++;
    }

    display(vec);
}

void test3()
{
    std::vector<int> vec{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it = vec.cbegin();

    while (it != vec.cend())
    {
        cout << *it << endl;
        it++;
    }

    /// change elements to zero //!can't change
    /*
    it = vec.begin(); // reset to begin
    while (it != vec.end())
    {
        *it = 0;
        it++;
    }
    */
}

void test4()
{
    std::list<std::string> name{"Larry", "moe", "curly"}; // doubly linked list
    auto it = name.crbegin();
    cout << *it << endl;
    it++;
    cout << *it << endl;

    std::map<std::string, std::string> favorites{
        {"Larry", "Buddy"},
        {"moe", "Daisy"},
        {"curly", "Shadow"}};
    auto mit = favorites.begin();

    while (mit != favorites.end())
    {
        // cout << (*mit).first << "-" << (*mit).second << endl;
        cout << mit->first << "-" << mit->second << endl;
        mit++;
    }
}

void test5()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto start = vec.begin() + 2; /// 3
    auto finish = vec.end() - 3;  /// 8

    while (start != finish)
    {
        cout << *start << endl;
        start++;
    }
}

int main()
{
    test1();
    cout << "=======================" << endl;
    test2();
    cout << "=======================" << endl;
    test3();
    cout << "=======================" << endl;
    test4();
    cout << "=======================" << endl;
    test5();
    return 0;
}