#include <iostream>

using std::cin;
using std::cout;
using std::endl;
unsigned long long fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    unsigned long long result = fact(4);
    cout << result << endl;
    return 0;
}