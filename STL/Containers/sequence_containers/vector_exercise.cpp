#include <iostream>
#include <vector>
#include "Person.hpp"

using std::cin;
using std::cout;
using std::endl;

/*
! NOTE:
- When we are using our own user defined types with STL always overload the < and == operators.
*/

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name << " " << rhs.age << endl;
    return os;
}

// using for_each and lambda to display vector elements
void display2(const std::vector<int> &vec)
{
    cout << "[";
    std::for_each(vec.begin(), vec.end(), [](int x)
                  { cout << x << " "; });
    cout << "]\n";
}

template <typename T>
void display(const std::vector<T> &vec)
{
    cout << "[";
    for (const auto &i : vec)
        cout << i << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 5}; // initialization list
    display(vec);

    vec = {2, 4, 5, 6};
    display2(vec);

    std::vector<int> vec1(10, 100); // overloaded constructor
    display(vec1);
}

void test2()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.push_back(6);
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.shrink_to_fit(); // this will shrink the storage allocated exactly to the vector size
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.reserve(100); // vec has now capacity 100, wont expand until size reaches 100
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;
}

void test3()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<Person> stooges;

    Person p1{"John", 14};
    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person("moe", 14));
    display(stooges);

    stooges.emplace_back("Test", 13);
    display(stooges);
}

void test4()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear();
    display2(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    display(vec);

    vec.erase(vec.begin(), vec.begin() + 2); // erase a piece of this vec
    display2(vec);

    vec.erase(vec.begin() + 3); // erase a single element using erase
    display2(vec);

    std::vector<int> vec1(10, 100); // overloaded constructor
    display(vec1);
}

// std::back_inserter constructs a back-insert iterator that inserts new elements
// at the end of the container it applied to. It's a special output iterator.
// There is also a front_inserter we can use with deques and list
// copy one list to another using an iterator and back_inserter.
void test5()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20};

    display(vec1);
    display(vec2);
    cout << endl;

    // using copy algorithm and back_inserter
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    display(vec1);
    display(vec2);
    cout << endl;

    // copy_if the element is even

    // using copy algorithm and back_inserter
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
                 [](int x)
                 { return x % 2 == 0; });

    // std::front_inserter is supported in list and deque.

    display(vec1);
    display(vec2);
    cout << endl;
}

/*
The std::transform function is a powerful algorithm in C++ that applies a specified operation to each element of one or more input ranges and stores the result in an output range. In your case, it's transforming elements from vec1 and vec2 and storing the results in vec3.

Here's a breakdown of how this std::transform works:

Input Ranges:
vec1: The first input range containing the elements {1, 2, 3, 4, 5}.
vec2: The second input range containing the elements {10, 20, 30, 40, 50}.

Output Range:
vec3: The output range where the results of the transformation will be stored.

Operation:
The lambda function [](int x, int y) { return x * y; } is used as the operation to be applied to each pair of corresponding elements from vec1 and vec2. It multiplies each element from vec1 with the corresponding element from vec2.

Back Inserter:
std::back_inserter(vec3): The result of each multiplication is then appended to vec3 using std::back_inserter, which is an iterator that inserts elements at the end of the container.

Transformation Process:
For each corresponding pair of elements (x, y) from vec1 and vec2, the lambda function is applied: x * y.
The result of each multiplication is then added to the end of vec3 using std::back_inserter.

Final Result:
After the transformation is complete, vec3 contains the transformed elements, which are the products of the corresponding elements from vec1 and vec2: {10, 40, 90, 160, 250}.

*/
void test6()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    // transform over 2 ranges.
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    // std::vector<int> vec3(vec1.size());
    std::vector<int> vec3;

    // std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(),
    //                [](int x, int y)
    //                {
    //                    return x * y;
    //                });

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), // no need to mention vec2.end
                   [](int x, int y)
                   {
                       return x * y;
                   });

    std::transform(vec1.begin(), vec1.begin() + 3, // Only transform the first three elements
                   vec2.begin(),
                   std::back_inserter(vec3), // for back_inserter size of vec3 not specified also OK,
                   [](int x, int y)
                   {
                       return x * y;
                   });

    display(vec3);
}

void test7()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    display(vec1);
    display(vec2);
    cout << endl;

    auto it = std::find(vec1.begin(), vec1.end(), 3);
    vec1.insert(it, vec2.begin(), vec2.end());

    display(vec1);
    cout << endl;
}

int main()
{
    // operations on vector
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}