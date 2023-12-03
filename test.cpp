#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a;   // garbage value
    int b{}; // initializes to zero
    cout << a << endl;
    cout << b;
    bool al = true;
    cout << boolalpha << al;
    return 0;
}
