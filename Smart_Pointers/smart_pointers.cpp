#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*
!Smart POinters:
- are objects
- are c++ template classes which we can instantiate.
- only point to heap allocated memory and automatically delete when no longer needed.
- Types:
    - Unique pointer
    - Shared pointer
    - Weak pointer
- To use smart pointer include <memory> header file.
- They are basically like wrapper classes and contain and manage the raw pointers.
- we can use *,-> operators on smart pointers but pointer arithmetic is not supported.
- we can have custom deleters for smart pointers.
*/

/*
! Unique Pointer:
- It is unique - there can be one unique_ptr<T> pointing to the object on the heap.
- owns what it points to
- can't be assigned or copied
- can be moved
- when the pointer is destroyed , what it points to is automatically destroyed.
*/

int main()
{
    std::unique_ptr<int> p1{new int(100)};

    //? unique pointer methods:
    if (p1)
        cout << *p1 << endl;

    cout << p1.get() << endl; // returns the pointer to the managed object 0x564388
    p1.reset();               // p1 is now nullptr
    if (p1)
        cout << *p1 << endl;

    //? unique-ptr vectors and move
    vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> ptr{new int{1000}};

    vec.push_back(ptr);            //! Error- copy not allowed.
    vec.push_back(std::move(ptr)); // instead of copy we have to move the pointer using move method.

    return 0;
}