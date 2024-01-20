#include <iostream>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;

void display(const std::map<std::string, std::set<int>> &m)
{
    cout << " <nested display> " << endl;
    std::cout << "[ ";
    for (const auto &elem : m)
    {
        std::cout << elem.first << ": [ ";
        for (const auto &set_elem : elem.second)
            std::cout << set_elem << " ";
        std::cout << "] ";
    }
    std::cout << "]  " << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l)
{
    cout << " <template based display> " << std::endl;
    std::cout << "[ ";
    for (const auto &elem : l)
    {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}

void test1()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::map<std::string, int> m{
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}};
    display(m);

    m.insert(std::pair<std::string, int>("Anna", 10));
    display(m);

    m.insert(std::make_pair("Joe", 5));
    display(m);

    // we can also insert new pair using
    m["Frank"] = 18;
    display(m);

    // we can also update Frank using
    m["Frank"] += 2;
    display(m);

    // erase pair from map
    m.erase("Frank");
    display(m);

    // count of pairs
    cout << "Count joe: " << m.count("Joe") << endl;
    cout << "Count Frank: " << m.count("Frank") << endl;

    auto it = m.find("Larry");
    if (it != m.end())
        cout << "found " << it->first << ":" << it->second << endl;

    m.clear();
    display(m);
}

void test2()
{
    cout << "=-=-=-=-=-=-=-=-" << endl;
    std::map<std::string, std::set<int>> grades{
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}};

    display(grades);

    // inserting values into particular set
    grades["Larry"].insert(95); // grades["Larry"] returns the reference which can be used to insert value.
    display(grades);

    auto it = grades.find("Moe"); // found Moe
    if (it != grades.end())
        it->second.insert(1000); // insert 1000 into Moe's set it->first is key and it->second is the value.
    display(grades);
}

int main()
{
    // operations on map :
    test1();
    test2();

    // std::map<std::string, int> m{
    //     {"Larry", 3},
    //     {"Moe", 1},
    //     {"Curly", 2}};

    // cout << m["Larry"] << endl;
    return 0;
}