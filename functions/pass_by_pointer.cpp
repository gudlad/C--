#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void double_data(int *p)
{
    *p *= 2;
}
int main()
{
    int value{10};
    int *ptr{&value};
    double_data(&value);
    cout << value << endl;
    //! OR
    double_data(ptr);
    cout << value << endl;

    return 0;
}