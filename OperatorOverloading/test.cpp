#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int *a = new int{13}; // or int(13)
    cout << *a;
    return 0;
}