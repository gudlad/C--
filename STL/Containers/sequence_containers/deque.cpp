#include <iostream>
#include <deque>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*

! Using STL DEQUE: (double ended queue)
- Dynamic size
- elements are not stored in contiguous memory
- direct element access, constant time
- Rapid insertion and deletion at the front and back, constant time
- insertion or removal of elements (linear time)
- all iterators are available and may invalidate.

- for deque methods refer cppref doc..

*/

template <typename T>
void display(const std::deque<T> &dec)
{
    cout << "[";
    for (const auto &i : dec)
        cout << i << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::deque<int> dec{1, 2, 3, 4, 5}; // initialization list
    display(dec);

    dec = {2, 4, 5, 6};
    display(dec);

    dec[0] = 100;
    dec.at(1) = 200;
    display(dec);
}

//! if there is need for inserting elements into middle then don't use deque use list.
void test2()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::deque<int> dec{0, 0, 0}; // initialization list
    display(dec);

    dec.push_back(10);
    dec.push_back(20);
    display(dec);

    dec.push_front(100);
    dec.push_front(200);
    display(dec);

    cout << dec.front() << endl;
    cout << dec.back() << endl;
    cout << dec.size() << endl;

    dec.pop_back();
    dec.pop_front();
    display(dec);
}

// we can use both back_inserter and front_inserter on deque.
void test3()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::deque<int> dec;

    std::copy(vec.begin(), vec.end(), std::front_inserter(dec));
    display(dec);

    dec.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(dec));
    display(dec);
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}