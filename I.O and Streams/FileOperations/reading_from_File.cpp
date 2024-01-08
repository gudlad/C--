#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

/*
! Reading from files:
- fstream and ifstream are commonly used for input files

Steps:

- #include<fstream>
- Declare an fstream or ifstream object
- Connect it to a file on the file system ( open's it for reading )
- we can read the file in different ways (text , binary ) , one line at a time or one character etc.
- Read data from the file via the stream
- Close the stream.

*/
int main()
{
    std::fstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");

    if (!in_file)
    {
        std::cerr << "failed" << endl;
        return 1;
    }

    /*
      while (in_file.eof())
      {
          in_file >> line >> total >> num;
          cout << line << endl
               << total << endl
               << num;
      }
  */
    while (in_file >> line >> total >> num)
        cout << std::setw(5) << line << std::setw(10) << total << std::setw(10) << num << endl;

    in_file.close();
    return 0;
}