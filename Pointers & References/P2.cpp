#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// The main use case of pointers is *DYNAMIC MEMORY ALLOCATION*
int main()
{
    int *intPtr{nullptr};
    intPtr = new int; // allocate storage on heap.
    *intPtr = 100;
    cout << "Value at address: " << intPtr << " = " << *intPtr << endl;
    delete intPtr; // frees allocated storage.

    // allocate array of int
    int *arrayPointer{nullptr};
    size_t size{4};
    arrayPointer = new int[size];

    cout << endl;
    *arrayPointer = 999;
    *(arrayPointer + 1) = 998;
    cout << *arrayPointer << endl;
    cout << *(arrayPointer + 1) << endl;
    delete[] arrayPointer;
    return 0;
}