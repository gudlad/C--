#include <iostream>
#include <iomanip>

/*

iostream - Provides definitions for formatted input and output from/to streams.

ifstream - Provides for high-level input operations on file based streams.
ofstream - Provides for high-level output operations on file based streams.
fstream  - Provides definitions for formatted input and output from/to file streams (derived from ifstream and ofstream)

iomanip  - Provides definitions for manipulators used to format stream I/O.

stringstream - Provides for high-level I/O operations on memory based strings
            - Derived from istringstream ostringstream.

!IOMANIP:
! 1) Stream Manipulators
- Streams have useful member functions to control formatting
- Can be used on input and output streams
- The time of the effect on streams varies
- Can be used as member functions or as a manipulators.

*/

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // formatting boolean types
    cout << std::boolalpha; // manipulator
    cout << (0 == 0) << endl;
    cout << std::noboolalpha; // manipulator
    cout << (0 == 0) << endl;

    cout.setf(std::ios::boolalpha); // doing the same thing using method.
    cout << (0 == 0) << endl;

    cout << std::resetiosflags(std::ios::boolalpha);

    cout << (0 == 0) << endl;

    return 0;
}