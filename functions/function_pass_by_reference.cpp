#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print(vector<int> &v);       // pass by reference without const
void print(const vector<int> &v); // pass by reference with const

void print(const vector<int> &v)
{
    for (auto i : v)
        cout << i << endl;
}
int main()
{
    vector<int> data{1, 2, 3, 4}; // pass by reference
    print(data);
    return 0;
}