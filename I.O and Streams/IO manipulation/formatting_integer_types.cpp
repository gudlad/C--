#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num{234};
    int num2{-234};

    cout << std::showbase;  // std::noshowbase
    cout << std::uppercase; // std::nouppercase
    cout << std::dec << num << endl;
    cout << std::hex << num << endl;
    cout << std::oct << num << endl;
    cout << std::noshowbase;

    cout << std::resetiosflags(std::ios::basefield); // resets the no system back to decimal.

    cout << std::showpos; // std::noshowpos
    cout << num << endl;

    cout << std::noshowbase;
    cout << std::nouppercase;
    cout << std::noshowpos;

    // same can be done with methods
    // using setf
    cout.setf(std::ios::showbase);
    cout.setf(std::ios::uppercase);
    cout.setf(std::ios::showpos);
    cout << num << endl;

    // reset to defaults
    cout << std::resetiosflags(std::ios::showbase);
    cout << std::resetiosflags(std::ios::showpos);
    cout << std::resetiosflags(std::ios::uppercase);

    return 0;
}