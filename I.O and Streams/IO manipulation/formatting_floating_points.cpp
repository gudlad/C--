#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double num{1234.567891};
    double num2{123456789.987654321};
    cout << num << endl;  // precision is 6
    cout << num2 << endl; // precision is 6
    cout << "---------------------------------------------" << endl;

    cout << std::setprecision(9);
    cout << num << endl;  // precision is 9
    cout << num2 << endl; // precision is 9
    cout << "---------------------------------------------" << endl;

    // fixed and precision (precision happens after the decimal point)
    cout << std::setprecision(3) << std::fixed;
    cout << num << endl;
    cout << num2 << endl;
    cout << "---------------------------------------------" << endl;

    cout << std::setprecision(3) << std::fixed << std::scientific << std::showpos << std::uppercase;
    cout << num << endl;
    cout << num2 << endl;
    cout << "---------------------------------------------" << endl;

    // back to defaults
    cout.unsetf(std::ios::scientific | std::ios::fixed);
    cout << std::resetiosflags(std::ios::showpos | std::ios::uppercase);

    // show trailing zeroes upto precision 10
    double n3{123.45};
    double n4{34.34};
    cout << std::setprecision(10) << std::showpoint;
    cout << n3 << endl;
    cout << n4 << endl;

    // back to defaults
    cout << "---------------------------------------------" << endl;
    cout.unsetf(std::ios::showpoint);
    cout << n3 << endl;
    cout << n4 << endl;
    return 0;
}