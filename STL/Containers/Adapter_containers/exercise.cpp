#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// challenge:
// checking a string palindrome using stack and queue.

bool is_palindrome(const std::string &str)
{
    std::stack<char> s;
    std::queue<char> q;

    // add all the characters that are alpha to back of queue in uppercase
    // push all the characters that are alpha on the stack

    for (char c : str)
    {
        if (std::isalpha(c))
        {
            q.push(c);
            s.push(c);
        }
    }
    char c1{};
    char c2{};

    // while the queue is not empty
    // compare and remove the characters at the top of the stack
    // and the characters at front of the queue
    // if they are not same - return false
    // if loop completed then return true
    while (!q.empty())
    {
        c1 = q.front();
        q.pop();
        c2 = s.top();
        s.pop();
        if (c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> args{
        "a",
        "aa",
        "abba",
        "aba",
        "is palindrome",
        "radar"};

    cout << std::boolalpha;
    for (auto element : args)
        cout << element << " " << is_palindrome(element) << endl;
    return 0;
}