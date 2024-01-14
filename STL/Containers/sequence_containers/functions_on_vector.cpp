#include <iostream>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::vector<int> v{1, 5, 3, 0};
    //! 1. sorting.
    std::sort(v.begin(), v.end());
    for (auto ele : v)
        cout << ele << endl;

    cout << endl;

    //! 2. reversing
    std::reverse(v.begin(), v.end());
    for (auto ele : v)
        cout << ele << endl;

    cout << endl;

    //! 3. accumulate
    // use 0 for int sum , 0.0 for double sum.
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << sum << endl
              << endl;

    return 0;
}