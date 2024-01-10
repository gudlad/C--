#include <iostream>
#include "Array_template_class.hpp"

using std::cin;
using std::cout;
using std::endl;

/*

! NOTE:
?- Since C++11 the STL has std::array which is a template-based array class
?- Use std::array instead of raw arrays whenever possible

! whenever we need fixed sized array in C++ use std::array.
*/

int main()
{
    /*
    Array<5> nums;
    cout << "the  of nums:" << nums.get_size() << endl;
    cout << nums << endl;

    nums.fill(0);
    cout << "the size of nums:" << nums.get_size() << endl;
    cout << nums << endl;

    nums.fill(10);
    cout << nums << endl;

    nums[0] = 1000; // nums.operator[](0)
    nums[3] = 2000;
    cout << nums << endl;

    Array<100> nums2{1};
    cout << "the size of nums2:" << nums2.get_size() << endl;
    cout << nums2 << endl;
    */

    Array<int, 5> nums;
    cout << "the  of nums:" << nums.get_size() << endl;
    cout << nums << endl;

    nums.fill(0);
    cout << "the size of nums:" << nums.get_size() << endl;
    cout << nums << endl;

    nums.fill(10);
    cout << nums << endl;

    nums[0] = 1000; // nums.operator[](0)
    nums[3] = 2000;
    cout << nums << endl;

    Array<int, 100> nums2{1};
    cout << "the size of nums2:" << nums2.get_size() << endl;
    cout << nums2 << endl;

    Array<std::string, 10> strings{std::string{"guru"}};
    cout << "the size of strings:" << strings.get_size() << endl;
    cout << strings << endl;

    strings[0] = std::string{"Larry"};
    strings[2] = std::string{"xxx"};
    cout << strings << endl;

    strings.fill("x");
    cout << strings << endl;

    return 0;
}