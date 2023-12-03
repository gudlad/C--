#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int *intPtr{nullptr}; // pointer is initalized to 0 or null
    cout << intPtr << endl;

    long long a = 13445;
    long long *lPtr{&a}; // Pointer points to type long long , what they point to can be simple or complex (obj)
    cout << *lPtr << endl;

    //? string pointer
    string name = "guru";
    string *namePtr = &name;
    cout << *namePtr << endl;
    name = "prasad";
    cout << *namePtr << endl;

    //? vector pointer
    vector<string> stooges{"Larry", "More", "Curly"};
    vector<string> *vPtr{nullptr};
    vPtr = &stooges;

    cout << (*vPtr).at(0) << endl; // accessing using . operator
    //! OR
    cout << vPtr->at(0) << endl; // accessing using -> operator the -> operator doesn't need * operator to access the values

    for (auto i : *vPtr)
        cout << i + ",";
    cout << endl;
    cout << endl;

    return 0;
}