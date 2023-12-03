#include <iostream>

int addNumbers(int a, int b)
{
    return a + b;
}
int main(int argc, char **argv)
{
    int firstNumber{5};
    // uniform initialization modern way c++11 onwards
    // recommended for initialization to avoid issues related to narrowing conversions and to ensure consistency.
    int secondNumber = 1;
    std::cout << " sum : " << addNumbers(firstNumber, secondNumber);
}