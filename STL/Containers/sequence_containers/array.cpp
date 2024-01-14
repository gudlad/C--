#include <iostream>
#include <array>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;

/*

! std::array ::

- size must be known at compile time.
- std::array is a object and doesn't decay into pointers like raw array.
- direct element access, access time is constant for any no of elements.
- provides access to underlying raw array, like wrapper over raw array.
- use instead of raw arrays when possible.
- all iterators available and don't invalidate.

*/
void display(const std::array<int, 5> &arr)
{
    cout << "[";
    for (const auto i : arr)
        cout << i << ", ";
    cout << "]" << endl;
}

// std::array - initialization and assignment
void test1()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5}; // arr1{{1,2,3,4,5}} in case of C++11
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2); // elements not initalized contain garbage

    arr2 = {10, 20, 30, 40, 50}; // assign values.

    display(arr1);
    display(arr2);

    cout << "size of arr1 " << arr1.size() << endl;
    cout << "size of arr2 " << arr2.size() << endl;

    arr1[0] = 1000;    // doesn't do bounds checking
    arr1.at(1) = 2000; // checks bounds checking, if out of bounds throws an exception
    display(arr1);

    cout << "front of arr2 " << arr2.front() << endl;
    cout << "back of arr2 " << arr2.back() << endl;
}

// fill and swap
void test2()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
}

// getting base address of raw array from array object
void test3()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};

    int *ptr = arr1.data(); // returns raw pointer to the array (base address)
    cout << *ptr << endl;

    *ptr = 10000;

    display(arr1);
}

// sorting array
void test4()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{2, 1, 3, 9, 8};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

// finding min max
void test5()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{2, 1, 3, 9, 8};
    std::array<int, 5>::iterator max = std::max_element(arr1.begin(), arr1.end());
    auto min = std::min_element(arr1.begin(), arr1.end());

    cout << "max " << *max << " min " << *min << endl;
}

// adjacent items founder
void test6()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{2, 1, 3, 3, 8};

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        cout << "adjacent item:" << *adjacent << endl;
}

// finding sum using accumulate
// accumulate is from #include <numeric>
void test7()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{2, 1, 3, 3, 8};

    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    cout << "sum " << sum << endl;
}

// count an element
void test8()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 5> arr1{3, 1, 3, 3, 8};

    int count = std::count(arr1.begin(), arr1.end(), 3);
    cout
        << "count 3: " << count << endl;
}

// count elements based on condition
void test9()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    std::array<int, 10> arr1{1, 2, 3, 50, 60, 80, 200, 300, 400, 5};

    int count = std::count_if(arr1.begin(), arr1.end(), [](int i)
                              { return (i > 10 && i < 200); });
    cout
        << "count : " << count << endl;
}

int main()
{
    // various operations on std::array...
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}