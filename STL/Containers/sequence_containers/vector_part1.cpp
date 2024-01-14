#include <iostream>

//? required for vector
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/*

! USING STL VECTOR class:

!points about vector:
- Arrays are fixed in size use vectors for dynamic size array
- Vectors are just like arrays but very efficient and provides constant access.
- Inserting element at back of vector is efficient than other parts (linear time).
- Vector is an object that comes with many useful methods
- Elements are stored in continuous memory and as vector size exceeds new larger memory is allocated and current element are moved into it.
- Vector supports all the iterators and they can become invalid (when vector resizes)

*/

int main()
{

    //! declaring vectors
    vector<char> vowels(5);
    vector<int> test_Scores(10);     // vector of size 10
    vector<int> test_scores(3, 299); // 3 elements sized vector initialzed to 299

    //! declaring and initialization of vectors
    vector<double> temperatures{56.5, 14, 23.4};

    //! accessing the elements
    cout << temperatures[1] << endl;

    //! or using .at(index) method
    cout << temperatures.at(0) << endl;

    // setting values
    temperatures.at(0) = 999;

    //! vector will automatically allocate the required space
    // .push_back(val) adds element to the back of the vector
    temperatures.push_back(1000);

    //! size() method
    cout << temperatures.size() << endl;
    cout << temperatures.capacity() << endl; // current capacity of the vector

    return 0;
}
