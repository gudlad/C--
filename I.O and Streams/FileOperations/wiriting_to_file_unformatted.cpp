#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::ifstream in_file{"test.txt"};
    std::ofstream out_file{"my_file2.txt"};
    if (!in_file || !out_file)
    {
        std::cerr << "Operation failed" << endl;
        return 1;
    }
    /*
    !formatted.
    std::string line{};
    while (std::getline(in_file, line))
    {
        out_file << line;
    }
    */

    // ! unformatted.
    char c{};
    while (in_file.get(c)) // read a character
    {
        out_file.put(c); // write a character
    }
    in_file.close();
    out_file.close();
    return 0;
}