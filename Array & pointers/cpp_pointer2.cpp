#include <iostream>
using std::cout;

void getMinMax(int a[], int size, int *min, int *max)
{
    for (int i = 1; i < size; i++)
    {
        if (a[i] < *min)
            *min = a[i];
        if (a[i] > *max)
            *max = a[i];
    }
}

int main()
{
    // returning multiple values using pointer
    int a[] = {5, 4, -1, 2, 100};
    int min = a[0];
    int max = a[0];
    getMinMax(a, 5, &min, &max);
    cout << min << " " << max;
    return 0;
}
