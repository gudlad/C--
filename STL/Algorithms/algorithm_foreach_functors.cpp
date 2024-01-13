#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
! Algorithm :for_each

- applies a function to each element in the iterator sequence.
- Function must be provided to algorithm as:
    -> Functor (function object)
    -> Function pointer
    -> Lambda expression ( modern C++)

! USING FUNCTORS : ( class or struct )
? NOTE: The container elements are not modified.
*/

struct Square_Functor // struct or class with single  public method.
{
    void operator()(int x) // overload () operator
    {
        cout << x * x << " ";
    }
};

Square_Functor square; // Function object
int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), square); // square() will be called on each int,
    cout << endl;
    return 0;
}