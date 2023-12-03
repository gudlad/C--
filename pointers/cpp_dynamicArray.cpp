#include <iostream>
using std::cout;

int main()
{
    int size;
    cout << "enter size" << std::endl;
    std::cin >> size;
    int *myArray = new int[size];

    cout << "enter elements;" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> myArray[i];
    }

    cout << "entered elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " => " << myArray[i] << std::endl;
    }

    // free the memory
    delete[] myArray;
    myArray = NULL;
    return 0;
}
