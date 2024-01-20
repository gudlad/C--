#include <iostream>
#include <set>
#include "Person.hpp"

using std::cin;
using std::cout;
using std::endl;

/*

! Using STL SET:
- similar to mathematical set
- Ordered by key
- No duplicates
- All iterators are available and invalidated when corresponding element is deleted.
- uses the operator< for ordering of elements.
- insert return std::pair<iterator,bool>
*/

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name << ":" << rhs.age << " ";
    return os;
}

template <typename T>
void display(const std::set<T> &set)
{
    cout << "[";
    for (const auto &i : set)
        cout << i << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::set<int> s1{1, 4, 3, 5, 2};
    display(s1);

    s1 = {1, 2, 3, 1, 1, 2, 3, 5, 3, 4, 6};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if (s1.count(10))
        cout << "10 is in set" << endl;
    else
        cout << "10 is not in set" << endl;

    auto it = s1.find(5);
    if (it != s1.end())
        cout << "Found " << *it << endl;

    s1.clear();
    display(s1);
}

void test2()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::set<Person> stooges{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}

    };                // to do the ordering the set uses the operator <
    display(stooges); // Note : the order or display! operator<

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50); // No -- 50 already exists.
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);

    display(stooges);

    it = stooges.find(Person{"XXX", 50}); // will remove james!!!
                                          // uses operator< so it removes which has 50
    stooges.erase(it);
    display(stooges);
}

void test3()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::set<char> s{'A', 'B', 'C'};
    display(s);

    auto result = s.insert('D');
    // result is a std::pair ,
    // here first is an iterator i.e pointer to inserted D or already existing D incase of duplicate.
    // second is boolean true/false status of insertion
    display(s);

    cout << std::boolalpha;
    cout << "first " << *(result.first) << endl;
    cout << "second " << result.second << endl;

    result = s.insert('A');
    cout << "first " << *(result.first) << endl;
    cout << "second " << result.second << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}