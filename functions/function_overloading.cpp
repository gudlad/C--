#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(int);
void print(std::string);
void print(vector<string>);
void print(double);

void print(int i)
{
    cout << i << endl;
}

void print(string i)
{
    cout << i << endl;
}

void print(double i)
{
    cout << i << endl;
}
void print(vector<string> i)
{
    for (auto s : i)
        cout << s << endl;
}
int main()
{
    print(13);
    print('A');
    print("Hello"); // c style string -> converted to C++ style string i.e std::string="Hello"
    print(13.50);
    print(13.5F);
    vector<string> vector_strings{"Larry", "Don"};
    print(vector_strings);
    return 0;
}