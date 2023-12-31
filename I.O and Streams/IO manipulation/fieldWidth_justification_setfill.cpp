#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

void ruler()
{
    cout << "\n123456789012345678901234567890" << endl;
}

int main()
{
    int num1{1234};
    double num2{1234.5678};
    std::string hello{"Hello"};

    ruler();
    cout << num1
         << num2
         << hello
         << endl;
    cout << "--------------------------------" << endl;

    // set field width to 10
    // Note the default justification is right for num1 only
    // no width associated with num2 and string
    ruler();
    cout << std::setw(10)
         << num1
         << num2
         << hello
         << endl;
    cout << "--------------------------------" << endl;

    ruler();
    cout << std::setw(10)
         << num1
         << std::setw(10)
         << num2
         << std::setw(10)
         << hello
         << endl;

    cout << "--------------------------------" << endl;

    //  left justified
    ruler();
    cout << std::setw(10)
         << std::left
         << num1
         << std::setw(10)
         << std::left
         << num2
         << std::setw(10)
         << std::left
         << hello
         << endl;

    cout << "--------------------------------" << endl;

    // setfill to a dash
    cout << std::setfill('-');
    ruler();
    cout << std::setw(10)
         << std::left
         << num1
         << std::setw(10)
         << std::left
         << num2
         << std::setw(10)
         << std::left
         << hello
         << endl;

    cout << "--------------------------------" << endl;

    // setfill to a dash
    ruler();
    cout << std::setw(10)
         << std::left
         << std::setfill('*')
         << num1
         << std::setw(10)
         << std::left
         << std::setfill('#')
         << num2
         << std::setw(10)
         << std::left
         << std::setfill('$')
         << hello
         << endl;

    cout << endl
         << endl;
    return 0;
}