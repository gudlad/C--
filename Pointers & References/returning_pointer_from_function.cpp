#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *largest_int(int *ptr1, int *ptr2)
{
    if (*ptr1 > *ptr2)
        return ptr1;
    return ptr2;
}

int main()
{
    int a{100}, b{200};
    int *largestPointer = largest_int(&a, &b);
    cout << *largestPointer << endl;
    return 0;
}