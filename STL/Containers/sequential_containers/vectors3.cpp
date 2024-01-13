#include <iostream>

//? required for vector
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    // multi dimensional vector
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << matrix[0][0] << endl;
    // or
    cout << matrix.at(0).at(0) << endl;

    return 0;
}
