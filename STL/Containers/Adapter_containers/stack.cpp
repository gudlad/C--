#include <iostream>
#include <stack>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;

/*
! USING STL STACK:
- methods:
    push - insert an element at top of stack
    pop - remove an element at top of stack
    top - access the top of stack
    empty - is stack empty?
    size - number of elements in stack.

*/

// This function displays a stack by repeatedly topping and popping the stack
// Note : the stack is passed in value so we don't effect the original stack.
template <typename T>
void displays_stack(std::stack<T> s)
{
    cout << "[";
    while (!s.empty())
    {
        T element = s.top();
        cout << element << ",";
        s.pop();
    }
    cout << "]" << endl;
}

int main()
{
    // stack initialization
    std::stack<int> s; // uses deque by default
    // underlying implementations
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;

    for (int i : {1, 2, 3, 4, 5})
    {
        s.push(i);
    }
    displays_stack(s);

    s.push(100);
    displays_stack(s);

    s.pop();
    s.pop();
    displays_stack(s);

    while (!s.empty())
    {
        s.pop();
    }
    displays_stack(s);

    cout << "size" << s.size() << endl s.push(10);
    displays_stack(s);

    s.top() = 100; // the top returns the reference so we can modify the item.
    displays_stack(s);

    return 0;
}