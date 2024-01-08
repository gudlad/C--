#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

/*
!Using String Streams
- Allows us to read or write from strings in memory much as we would read and write to files.
- Very powerful
- Very useful for data validation.

!3 classes
- stringstream
- istringstream
- ostringstream

!how
- Declare the class object
- Connect it to a std::string
- Read/Write data from/to the string stream using formatted I/O.

*/

int main()
{
    int num{};
    double total{};
    std::string name{};

    std::string info{"Moe 100 1234.5"};
    std::istringstream iss{info}; // connect

    iss >> name >> num >> total; // extract
    cout << name << "-" << num << "-" << total << endl
         << endl;

    std::ostringstream oss{}; // has it's own buffer.
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << endl;

    cout << oss.str() << endl
         << endl; // convert to string

    //! Data validation using stringstream.
    int value{};
    std::string entry{};
    bool done = false;
    do
    {
        cout << "Please enter an integer" << endl;
        cin >> entry;
        std::istringstream ss{entry};
        if (ss >> value)
        {
            done = true;
        }
        else
            cout << "not an integer" << endl;

        // discards the input buffer.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);
    cout << "you entered int" << endl;
    return 0;
}