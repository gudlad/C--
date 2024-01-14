#include <iostream>
#include <list>
#include "Person.hpp"
#include <algorithm>
#include <iterator> // for std::advance

using std::cin;
using std::cout;
using std::endl;

/*

!Using STL LIST and FORWARD LIST ::
- sequence containers
- non-contiguous in memory
- no direct access to elements
- very efficient for inserting and deleting elements once an element is found.

!LIST
- acts as doubly linked list, each element linked to front and back element.
- dynamic size
- we can efficiently add or remove elements from anywhere in the list
- when we need a container where lot of insertion and deletions occur without direct access to elements then list is a best choice.

!FORWARD LIST
- acts as a singly linked list, we can only use it in one direction
- less overhead compared to list
- rapid insertion and deletion of elements anywhere in the container
- reverse iterators are not available
- iterators invalidated when corresponding element is deleted.

*/

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name << ":" << rhs.age << endl;
    return os;
}

template <typename T>
void display(const std::list<T> li)
{
    cout << "[";
    for (auto &i : li)
        cout << i << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::list<int> l1{1, 2, 3, 4, 5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("back");
    l2.push_back("front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5, 6, 7};
    display(l3);

    std::list<int> l4(10, 100);
    display(l4);

    cout << "size: " << l4.size() << endl;
    cout << "front: " << l4.front() << endl;
    cout << "back: " << l4.back() << endl;
    l4.clear();
    display(l4);

    l3.resize(4);
    display(l3);
    l3.resize(10);
    display(l3);

    std::list<Person> persons; // uses the Person default constructor.
    persons.resize(4);
    display(persons);
}

void test2()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l1);

    auto it = std::find(l1.begin(), l1.end(), 5);
    if (it != l1.end())
    {
        l1.insert(it, 100);
    }
    display(l1);

    std::list<int> l2{1000, 2000, 4000};
    l1.insert(it, l2.begin(), l2.end());
    display(l1);

    std::advance(it, -4);
    cout << *it << endl;

    l1.erase(it);
    // l1.clear();
    display(l1);
}

void test3()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::list<Person> l1{
        {"Larry", 19},
        {"Moe", 20},
        {"Curly", 21},
    };
    display(l1);

    std::string name;
    int age{};
    cout << "name: " << name << endl;
    getline(cin, name);
    cout << "age: " << endl;
    cin >> age;

    l1.emplace_back(name, age);
    display(l1);

    // insert Frank in front of Moe
    auto it = find(l1.begin(), l1.end(), Person{"Moe", 20}); // ==
    if (it != l1.end())
        l1.emplace(it, "Frank", 18);
    display(l1);

    // sorting the list
    l1.sort();
    cout << "after sorting ascending :" << endl;
    display(l1);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}