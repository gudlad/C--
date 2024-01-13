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

! USING LAMBDA EXPRESSION:
*/

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int x)
                  { cout << x * x << " " << endl; });
    return 0;
}