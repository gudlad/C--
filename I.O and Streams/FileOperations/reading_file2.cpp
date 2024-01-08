#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::fstream in_file;
    // std::string line;

    in_file.open("test.txt");

    if (!in_file)
    {
        std::cerr << "failed" << endl;
        return 1;
    }
    char line[256];

    // while (getline(in_file, line))
    // {
    //     cout << line << endl;
    // }

    while (in_file.getline(line, sizeof(line))) // using c style string.
    {
        cout << line << endl;
    }

    in_file.close();
    return 0;
}