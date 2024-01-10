#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"

using std::cin;
using std::cout;
using std::endl;

/*

!Generic Programming using Class Templates
- similar to functions template, but at the class level
- Allows plugging-in any data type
- compiler generates the appropriate specialized class from the blueprint.

*/

int main()
{
    Item<int> item1{"frank", 100};
    cout << item1.get_name() << " " << item1.get_value() << endl;

    Item<std::string> item2{"frank", "Professor"};
    cout << item2.get_name() << " " << item2.get_value() << endl;

    Item<Item<std::string>> item3{"frank", {"C++", "Professor"}};
    cout << item3.get_name()
         << " " << item3.get_value().get_name()
         << " " << item3.get_value().get_value()
         << endl;

    cout << "=========================================" << endl
         << endl;

    std::vector<Item<double>> vec{};
    vec.push_back(Item<double>{"Larry", 100.0});
    vec.push_back(Item<double>{"Moe", 200.0});
    vec.push_back(Item<double>{"Curly", 300.0});

    for (const auto &i : vec)
    {
        cout << i.get_name() << " " << i.get_value() << endl;
    }

    cout << "=========================================" << endl
         << endl;

    my_pair<std::string, int> p1{"Frank", 100};
    my_pair<int, double> p2{123, 12};
    cout << p1.first << "," << p1.second << endl;
    cout << p2.first << "," << p2.second << endl;

    return 0;
}