#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Deep copy:
- each object will have a unique pointer to the heap
- must be done when the object contains raw pointer members
- sometimes lead to overheads for large/many objects
*/
class Deep
{
    int *data; // raw pointer

public:
    Deep(int d);
    Deep(const Deep &obj);
    ~Deep();
    auto get_data()
    {
        return *data;
    }
    void set_data_values(int d)
    {
        *data = d;
    }
};

void display_Deep(Deep s)
{
    cout << s.get_data() << endl;
}

Deep::Deep(int d)
{
    data = new int;
    *data = d;
}

Deep::~Deep()
{
    delete data;
    cout << "destructor freeing data" << endl;
}

Deep::Deep(const Deep &source)
{
    data = new int; // create new storage and then copy values so both objs have different pointers.
    *data = *source.data;
    cout << " copy constructor Deep" << endl;
}

//! OR
/*
Deep::Deep(const Deep &source) : Deep{*source.data} // deep copy constructor- delegating constructor
{
}
*/

int main()
{
    Deep obj1{100};
    display_Deep(obj1); // now both obj1 and temporary obj have separate pointers and when temp obj is destroyed obj1 will be still intact.

    obj1.set_data_values(1000);
    Deep obj2{obj1};
    display_Deep(obj2); // same here.
    return 0;
}