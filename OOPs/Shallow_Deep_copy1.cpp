#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
shallow copy:
-member wise copy
-each data member is copied from the source object
-The pointer is copied not what it points to (shallow copy).
-Problem : when we release the storage in the destructor , the object is still refers to the released storage!
*/
class Shallow
{
    int *data; // raw pointer

public:
    Shallow(int d);
    Shallow(const Shallow &obj);
    ~Shallow();
    auto get_data()
    {
        return *data;
    }
};

void display_shallow(Shallow s)
{
    cout << s.get_data() << endl;
}

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
    cout << "shallow constructor" << endl;
}

Shallow::Shallow(const Shallow &source) : data(source.data) //? copy constructor.
{
    //! here we are only copying the pointer not its value so both source and newly created obj point to same memory area.
    cout << "copy constructor - shallow" << endl;
}

Shallow::~Shallow()
{
    delete data;
    cout << "destructor freeing data" << endl;
}
int main()
{
    Shallow obj1{100};
    display_shallow(obj1); // copy of obj1 is passed to function after function is done the temporary objs memory is released which causes obj1 to point to invalid memory location as both have same pointer value.
                           // obj1's data has been released! when we try to call destructor on obj1 we get errors.

    Shallow obj2{obj1}; // now both obj1 and obj2 pointing to invalid memory location , when destructor try to free memory pgm will crash.
    return 0;
}