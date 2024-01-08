#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

// reading file using unformatted get.

int main()
{
    std::fstream in_file;
    std::string line;

    in_file.open("test.txt");

    if (!in_file)
    {
        std::cerr << "failed" << endl;
        return 1;
    }
    char c;
    while (in_file.get(c))
    {
        cout << c;
    }

    in_file.close();
    cout << endl
         << endl;
    return 0;
}