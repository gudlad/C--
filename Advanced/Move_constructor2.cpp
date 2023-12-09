#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*

!Move Constructor for efficient code:
- Instead of making deep copy like the copy constructor does the move constructor moves the resources on the heap
by
- Assigning the pointer from the source object to the current object just like shallow copy(default member wise copy)
- After null-out the pointer at the source object ,Now we have an object who owns the data on the heap and the original object with the null pointer to that data.
This is found to be very efficient since we're not doing any copy of data.

*/

class Move
{
private:
    int *data;

public:
    Move(int d);
    Move(const Move &source); // normal copy constructor(shallow/deep)
    Move(Move &&source);      // move constructor
    ~Move();
};

Move::Move(int d)
{
    data = new int(d);
    cout << "constructor for " << *data << endl;
}

Move::Move(const Move &source)
{
    data = new int;
    *data = *source.data;
    cout << "Copy constructor deep copy for " << *data << endl;
}
Move::Move(Move &&source) //? "Steal" the data and then null out the source pointer.
{
    data = source.data;
    source.data = nullptr;
    cout << "Move constructor- moving resource." << *data << endl;
}
Move::~Move()
{
    if (data != nullptr)
        cout << "Destructor freeing data for " << *data << endl;
    else
        cout << "Destructor freeing data for null ptr" << endl;
    delete data;
}

int main()
{
    vector<Move> vec;
    vec.push_back(Move{10}); // Mov constructors will be called for the temporary r-values i.e Move{10},Move{20} instead of copy constructors.
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    return 0;
}
