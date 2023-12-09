#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *create_array(size_t size)
{
    return new int[size];
    // storage is on the heap Dynamically Allocated Memory
    // memory initalized to zero
}

//!    Don't do this ------------>
int *dont_do_this()
{
    int size{100};
    return &size;
}

int *or_this()
{
    int size{200};
    int *int_ptr{&size};
    return int_ptr;
}

int *orr_this()
{
    int array[]{1, 2, 3};
    return array;
}
//! ---------------------------->

int main()
{
    int *myArray{nullptr};
    size_t size{5};
    myArray = create_array(size);
    // use myArray;
    for (size_t i{0}; i < size; i++)
        cout << myArray[i] << endl;
    delete[] myArray; // free the memory on the heap

    /*                      //! segmentation fault
    int *p = dont_do_this();
    int *p2 = or_this();
    cout << "will give wrong output: " << *p << " " << *p2 << endl;

    int *p3 = orr_this();
    cout << *p3 + 1 << endl;

    */
    cout << endl;
    int *ptr{nullptr}; //! don't deference NUll pointer
    cout << *ptr;
    return 0;
}
