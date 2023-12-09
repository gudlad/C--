#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // ways to use const with pointers
    // 1. Pointer to constants
    // Data pointed by the pointer is constant can't be changed but the pointer can be changed to different address.
    int highScore{14};
    int lowScore{9};
    const int *score_ptr{&highScore};
    *score_ptr = 86;       //! ERROR
    score_ptr = &lowScore; //? OK

    // 2. Constant pointers
    // Pointer itself is constant it can't changed but data can be changed
    int *const score_ptr2{&highScore};
    *score_ptr2 = 100; //? OK
    // score_ptr2 = &lowScore; // !ERROR

    // 3. Constant pointers to constants
    const int *const ptr3{&highScore};
    *ptr3 = 3000;     //! ERROR
    ptr3 = &lowScore; //! ERROR

    return 0;
}