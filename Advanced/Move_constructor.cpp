#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*

MOVE constructor;
- copy constructors doing deep copy can have a significant performance bottleneck
- //! the move constructor moves an object rather than copy of it
- optional but recommended when you have a raw pointer.
- Copy elision - c++ may optimize copying away completely (RVO-return value optimization)
- move semantics is all about r-value references (&&)
- used by move constructor and move assignment operator to //! efficiently move an object rather than copy it.
*/

void func(int &lvalue_ref);
void func(int &&rvalue_ref);

int main()
{
    int x{100};
    int &l_ref = x; // l_ref l-value reference, x is l-value
    l_ref = 2000;

    int &&r_ref = 200; // r_ref is r-value reference, 200 is r-value (as it is temporary variable)
    r_ref = 4000;

    int b{300};
    func(b);   // b is l value
    func(300); // 300 is r value

    return 0;
}
