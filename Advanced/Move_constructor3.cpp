#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Move
{
private:
    int *data;

public:
    void set_data(int d);
    int get_data();
    Move(int d);
    Move(const Move &source); // normal copy constructor(shallow/deep)
    Move(Move &&source);      // move constructor
    ~Move();
};

void Move::set_data(int d)
{
    *data = d;
}

int Move::get_data()
{
    return *data;
}

Move::Move(int d)
{
    data = new int(d);
    cout << "constructor for " << d << endl;
}

Move::Move(const Move &source) : Move{*source.data}
{
    cout << "Copy constructor- deep copy for" << *data << endl;
}

Move::Move(Move &&source) //? "Steal" the data and then null out the source pointer.
{
    data = source.data;
    source.data = nullptr;
    cout << "Move constructor - moving resource." << *data << endl;
}

Move::~Move()
{
    if (data != nullptr)
        cout << "Destructor freeing data for." << *data << endl;
    else
        cout << "Destructor freeing data for null pointer" << endl;
    delete data;
}

int main()
{
    vector<Move> vec;
    vec.reserve(10);         //? Reserve space for 6 elements to avoid frequent reallocations
    vec.push_back(Move{10}); //? Very Inefficient if move constructor not called as lot of deep copies created.
    vec.push_back(Move{20}); //? If the vec.reserve is not done then as elements added new vec is created and elements are again and again copied to new vector which invokes the copy constructor even though we have move constructor.
    vec.push_back(Move{30}); //? So if we reserve vec size then new vec not create until size exceeds.
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});
    vec.push_back(Move{90});
    vec.push_back(Move{100});
    return 0;
}
