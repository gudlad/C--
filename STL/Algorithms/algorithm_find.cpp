#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
! STL Algorithms :
- Different containers support different types of iterators
*/

int main()
{
    std::vector<int> vec{1, 2, 3};
    auto loc = std::find(vec.begin(), vec.end(), 3);

    if (loc != vec.end())
        cout << *loc << endl;

    // find uses the = operator so for user defined types we have to overload the =

    return 0;
}