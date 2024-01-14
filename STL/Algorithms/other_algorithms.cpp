#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include "Person.hpp"

using std::cin;
using std::cout;
using std::endl;

void find_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 5};

    // vec.begin() is equivalent to std::begin(vec)
    auto Ioc = std::find(std::begin(vec), std::end(vec), 11);

    if (Ioc != std::end(vec)) // if element not found returns itr to pass the last element.
        cout << "found " << *Ioc << endl;
    else
        cout << "not found " << endl;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    std::list<Person> players{
        {"Larry", 14},
        {"John", 12},
        {"Curly", 11}};
    auto Itr = std::find(players.begin(), players.end(), Person{"Curly", 11});
    if (Itr != players.end())
        cout << "found " << endl;
    else
        cout << "not found " << endl;
}

// counts the no of elements in the container
void count_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 1, 6, 1, 8, 9};
    int num = std::count(vec.begin(), vec.end(), 1); // not found returns zero
    cout << num << endl;
}

void count_if_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    // count only if the element is  even
    std::vector<int> vec{1, 2, 3, 4, 1, 2, 100};
    int num = std::count_if(vec.begin(), vec.end(), [](int i)
                            { return i % 2 == 0; });
    cout << num << " even numbers found." << endl;
}

// replace occurrences of the elements in a container
void replace_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    std::vector<int> vec{1, 2, 3, 4, 1, 2, 100};

    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    std::replace(vec.begin(), vec.end(), 1, 1000);

    for (auto i : vec)
        cout << i << " ";
}

void all_of_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    std::vector<int> vec{1, 3, 5, 7, 9, 1, 3, 9, 0};

    if (std::all_of(vec.begin(), vec.end(), [](int x)
                    { return x < 10; }))
        cout << "All the elements are < 10" << endl;
    else
        cout << "All the elements are not < 10" << endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x)
                    { return x % 2 == 0; }))
        cout << "All the elements are even" << endl;
    else
        cout << "All the elements are not even" << endl;
}

void string_transform_test()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::string str1{"Hello, world!"};
    cout << "before transform : " << str1 << endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    cout << "after transform : " << str1 << endl;
}

int main()
{
    // STL algorithms:
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    // ... many other algorithms are there... around 90.. refer
    // http://en.cppreference.com/w/cpp/algorithm
    return 0;
}