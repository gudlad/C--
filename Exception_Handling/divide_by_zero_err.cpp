#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    try
    {
        throw 0;
    }
    catch (int &er)
    {
        cerr << "handled the error." << endl;
    }
    cout << "Exiting.." << endl;
    return 0;
}