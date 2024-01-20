#include <iostream>
#include <queue>
#include "Person.hpp"

using std::cin;
using std::cout;
using std::endl;

/*
! STL PRIORITY QUEUE:

 */

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name << " " << rhs.age << endl;
    return os;
}

template <typename T>
void displays_queue(std::priority_queue<T> pq)
{
    cout << "[";
    while (!pq.empty())
    {
        T element = pq.top();
        cout << element << ",";
        pq.pop();
    }
    cout << "]" << endl;
}

void test1()
{
    cout << "===========================" << endl;
    std::priority_queue<int> pq;

    // behind the scenes it's ordering, at the top largest element will be placed
    // uses heap to order the elements.
    for (int i : {1, 2, 3, 4, 5, 6, 7, 8})
    {
        pq.push(i);
    }

    cout << "size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;

    displays_queue(pq);

    pq.pop();
    displays_queue(pq);
}

void test2()
{
    cout << "===========================" << endl;
    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 10});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});

    displays_queue(pq);
}

int main()
{
    test1();
    test2();
}