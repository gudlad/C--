#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
void display(const std::vector<T> &vec)
{
    cout << "[";
    for (const auto i : vec)
        cout << i << " ";
    cout << "]" << endl;
}

int main()
{
    std::vector<int> vec;
    std::vector<std::string> stooges{
        std::string("Larry"),
        "John", // c-style string converted to cpp string
        std::string("Curly")};
    vec = {1, 9, -1, 4};
    std::vector<int> vec2{1, 2, 4, 6};

    cout << vec.front() << endl; // 1
    cout << vec.back() << endl;  // 4

    vec.pop_back(); // remove 4 from the back

    // vec.push_back(Person{"Larry",18}) uses move semantics

    /*
        vec.emplace_back("Larry", 18); //! very efficient
    */

    cout << vec.empty() << endl; // 0 false
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    display(vec);
    display(vec2);
    vec.swap(vec2); // swaps the 2 vectors
    display(vec);
    display(vec2);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    display(vec2);
    std::sort(vec2.begin(), vec2.end()); // sorts the vector.
    display(vec2);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    //! inserting the elements into vector other than the end using insert
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec3{10, 20, 30, 40, 50};

    display(vec1);

    // inserting one element into vector
    auto it = std::find(vec1.begin(), vec1.end(), 3);
    vec1.insert(it, 10); // 1,2,10,3,4,5

    display(vec1);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    display(vec1);

    // inserting entire range

    it = std::find(vec1.begin(), vec1.end(), 4);
    vec1.insert(it, vec3.begin(), vec3.end()); // 1, 2, 10, 3, 10, 20, 30, 40, 50, 4, 5

    display(vec1);

    return 0;
}

/*
!NOTE::
- Using emplace functions is often more efficient than using push_back or insert with pre-constructed objects.
- This is because emplace constructs the object directly in the vector's memory, eliminating the need for temporary objects and providing potential performance benefits.

* emplace and emplace_back are methods in C++ vectors that allow you to construct and insert elements directly into the vector without the need to create a temporary object separately.
* They are particularly useful for avoiding unnecessary copies and improving performance, especially when working with non-trivial types.

? emplace_back: This function adds a new element at the end of the vector. It constructs the element in place, forwarding its arguments directly to the constructor of the element type.
    std::vector<int> vec;
    vec.emplace_back(42);  // Constructs an int with the value 42 and adds it to the end of the vector

? emplace: This function allows you to insert an element at a specified position in the vector. It also constructs the element in place, forwarding its arguments to the constructor.
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin() + 2;
    vec.emplace(it, 10);  // Inserts an int with the value 10 at the third position in the vector
*/