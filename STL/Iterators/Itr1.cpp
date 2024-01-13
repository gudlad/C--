#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
!Using the STL Iterators:
- Iterators must be declared based on the container type they will iterate over.

!Syntax;
container_type :: iterator_type iterator_name;

*/

int main()
{
    std::vector<int> vec{1, 2, 3, 4};
    std::vector<int>::iterator it = vec.begin();

    while (it != vec.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl
         << "-------------" << endl;

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    cout << "------------ Reverse Iteration ---------------" << endl;

    /*

    The reverse iterator and iterator are different from each other can't assign one to another.

    In C++, rbegin() returns a reverse iterator pointing to the last element of the container, and rend() returns a reverse iterator pointing to one position before the first element of the container. The naming convention is consistent with the idea that rbegin() stands for "reverse begin" and rend() stands for "reverse end."
    rbegin(): Returns a reverse iterator pointing to the last element of the container. When dereferenced, it gives you access to the last element.
    rend(): Returns a reverse iterator pointing to one position before the first element of the container. It is often used as the stopping condition for reverse iteration. When dereferenced, it does not give you a valid value; it is just used as a sentinel to indicate the end of the reversed sequence.

    ? In reverse iterator incrementing means decrementing and visa-versa

    */

    std::vector<int>::reverse_iterator it3 = vec.rbegin();

    while (it3 != vec.rend())
    {
        cout << *it3 << endl;
        it3++;
    }

    return 0;
}