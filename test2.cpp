#include <iostream>
#include <iomanip>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a << std::setw(10) << b;
}