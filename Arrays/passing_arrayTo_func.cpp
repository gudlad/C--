#include <iostream>

using std::cin;
using std::cout;
using std::endl;
void dont_change_array(const int[], size_t);
void change_array(int[], size_t, int n); // when we don't want to accidentally change the passed value make it const so it can only be readonly

void change_array(int array[], size_t size, int value)
{
    for (int i = 0; i < size; i++)
        array[i] = value;
}

void dont_change_array(const int array[], size_t size)
{
    /*
    for (size_t i = 0; i < size; i++)   //! gives error when try to change read only
        array[i] = 0;
    */
    for (size_t i = 0; i < size; i++)
        cout << array[i] << endl;
}

int main()
{
    int my_array[]{100, 98, 93, 23, 45};
    dont_change_array(my_array, 5);
    change_array(my_array, 5, 999);
    return 0;
}