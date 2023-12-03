#include <iostream>
using std::cout;
using std::endl;

int getNumber()
{
    return 5;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int calculate(int a, int b, int (*funPtr)(int, int))
{
    return funPtr(a, b); // add or sub customization
}

int main()
{
    // the name of the function gives the address
    //! function pointers allows us to pass one function as an argument to another function
    // cout << getNumber;
    int (*funcPtr)() = getNumber;
    cout << funcPtr() << endl;

    // calculate performs add,sub,mul or div based on passed function pointer
    int (*functPtr2)(int, int) = add;
    int (*functPtr3)(int, int) = sub;
    int (*functPtr4)(int, int) = mul;
    int (*functPtr5)(int, int) = divide;
    cout << calculate(1, 2, functPtr2) << endl;
    cout << calculate(2, 2, functPtr3) << endl;
    cout << calculate(1, 2, functPtr4) << endl;
    cout << calculate(2, 2, functPtr5) << endl;

    return 0;
}

/*
src= https://www.youtube.com/watch?v=kiUGf_Z08RQ&t=4571s
*/