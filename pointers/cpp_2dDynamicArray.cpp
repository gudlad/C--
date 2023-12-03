#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int rows, cols;
    cout << "enter rows,cols" << endl;
    cin >> rows >> cols;
    int **table = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        table[i] = new int[cols];
    }
    cout << "enter values" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> table[i][j];
        }
    }

    cout << "values::" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " table[" << i << "][" << j << "]" << table[i][j];
        }
        cout << endl;
        1
    }

    // free memory
    for (int i = 0; i < rows; i++)
    {
        delete[] table[i];
    }
    delete[] table;
    table = NULL;
    return 0;
}
