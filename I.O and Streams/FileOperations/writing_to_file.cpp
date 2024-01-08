#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

/*

!Output files
- fstream and ofstream are commonly used for output files
- #include<fstream>
- Declare an fstream or ofstream object
- Connect it to a file on your file system
- Write data to the file via the system
- Close the stream.
- if the file not there a new file created

!different modes;
std::ofstream out_file {"my_file.txt",std::ios::trunc}
std::ofstream out_file {"my_file.txt",std::ios::app}
std::ofstream out_file {"my_file.txt",std::ios::ate}

*/

int main()
{
    //! if fstream is used then specify the flag std::ios::out
    /*

    std::fstream out_file{"my_file.txt", std::ios::out | std::ios::binary};

    */

    // or we can use ofstream without any flag of out
    // specify trunc,app flags
    /*

    std::ofstream out_file{"my_file.txt", std::ios::app};

    */
    //? OR ::
    std::ofstream out_file;
    std::string filename;
    cin >> filename;         // get file name from user
    out_file.open(filename); // write mode.

    if (!out_file.is_open()) // if(out_file)
        std::cerr << "failed";

    // formatted writing to file
    int a{100};
    double b{234.9};
    std::string c = "cat";

    out_file << a << endl
             << b << endl
             << c;

    out_file.close();

    return 0;
}