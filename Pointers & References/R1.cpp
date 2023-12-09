#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//? reference is an alias for a variable or obj
//? references can't be NULL
//? references once assigned can't be changed
//! references are constant pointers which are automatically dereferenced.
// USES of reference variables ::
//* as function parameters.
//* used in range based for loop.

int main()
{
    vector<string> stooges{"Larry", "More", "Curly"};

    for (auto i : stooges) // here i is a COPY of each vector element which is very in efficient
        i = "Funny";

    for (auto i : stooges) // No changes to the original vector
        cout << i << endl;
    //? ----------------------------------------------------------------//

    for (auto &i : stooges) // here i is a reference to each vector element which changes original data
        i = "Funny";

    for (auto const &i : stooges) // here i not copy of each vector element which is very efficient for large vectors.
        cout << i << endl;        // but there is possibility of accidentally modifying the elements so use const
    return 0;
}