#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    cout << "ENTER FULL NAME" << endl;
    getline(cin, fullName);
    cout << "YOUR FULL NAME:" << fullName;
    return 0;
}