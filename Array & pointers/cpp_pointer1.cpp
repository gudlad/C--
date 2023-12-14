#include <iostream>
using std::cout;

void print(void *ptr, char type)
{
    switch (type)
    {
    case 'i':
    {
        cout << *((int *)ptr);
        break;
    }
    }
}

int main()
{
    int a = 13;

    print(&a, 'i');
    return 0;
}
