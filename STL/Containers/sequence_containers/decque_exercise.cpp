#include <iostream>
#include <deque>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

bool is_palindrome(const std::string &str) // when passing string like string("aba") must use const.
{
    std::deque<char> deq;

    for (char c : str)
    {
        if (std::isalpha(c))
            deq.push_back(std::toupper(c));
    }
    char cf{};
    char ce{};
    while (deq.size() > 1) // aba aa
    {
        cf = deq.front();
        ce = deq.back();
        deq.pop_front();
        deq.pop_back();
        if (cf != ce)
            return false;
    }
    return true;
}

int main()
{
    cout << std::boolalpha;
    cout << "Result :" << is_palindrome(std::string("a santa at nasa")) << endl;

    return 0;
}