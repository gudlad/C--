#include <iostream>
#include <queue>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::endl;

/*
! Using the STL Queue:

- methods
    push - insert an element at the back of the queue
    pop - remove an element at the front of the queue
    front - access the element at the front
    back - access the element at the back
    empty - is the queue empty?
    size - no of elements in the queue

*/

// This function displays a stack by repeatedly topping and popping the stack
// Note : the stack is passed in value so we don't effect the original stack.
template <typename T>
void displays_queue(std::queue<T> q)
{
    cout << "[";
    while (!q.empty())
    {
        T element = q.front();
        cout << element << ",";
        q.pop();
    }
    cout << "]" << endl;
}

int main()
{
    // Queue initialization
    std::queue<int> q; // uses deque by default

    std::queue<int, std::list<int>> q2;
    std::queue<int, std::deque<int>> q3;

    for (int i : {1, 2, 3, 4, 5})
    {
        q.push(i);
    }
    displays_queue(q);
    cout << "front" << q.front() << endl;
    cout << "back" << q.back() << endl;

    q.push(100);
    displays_queue(q);

    q.pop();
    q.pop();
    displays_queue(q);

    while (!q.empty())
    {
        q.pop();
    }
    displays_queue(q);

    cout << "Size" << q.size() << endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    displays_queue(q);

    cout << "front" << q.front() << endl;
    cout << "back" << q.back() << endl;

    q.front() = 5;
    q.back() = 5000;

    displays_queue(q);
    cout << "front" << q.front() << endl;
    cout << "back" << q.back() << endl;

    return 0;
}