#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
!Generic Programming with template functions...
- C++ template is a Blueprint
- there are function and class templates
- Allow plugging-in any data type
- compiler generates the appropriate function/class from the blueprint
- Generic programming / meta programming
- All of this happens at compile time as compiler does it.
*/

/*
! Function Templates:
- max function as a template function

    T max ( T a, T b)
    {
        return (a>b)? a: b;
    }
*/

template <typename T>
// we need to explicitly tell the compiler that this is a template function.
// here T is a typename that will be replaced with whatever the user needs.
// this is simply a blue print.
// typename or class both are same.

const T &max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T, typename U>
void func(T a, U b)
{
    cout << a << " " << b << endl;
}

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

struct Person // in structure everything is public.
{
    std::string name;
    int age;
    bool operator<(const Person &rhs) const // member method.
    {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) // everything is public so we don't need friend function.
{
    os << rhs.name << "," << rhs.age << endl;
    return os;
}

int main()
{
    int a{10};
    int b{20};
    cout << max<int>(a, b) << endl; // this line tells the compiler to generate specialized code using int inplace of T.
    cout << max<double>(10.1, 20.9) << endl;
    cout << max(20.1, 30.9) << endl; // template argument deduction to determine the appropriate type.
    cout << max<char>('A', 'Z') << endl;

    // user type.
    Person p1{"curly", 50};
    Person p2{"Moe", 30};
    Person p3 = min(p1, p2);
    cout << p3.age << "=" << p3.name << endl;

    // different type T and U
    func<int, int>(10, 20);
    func(1, 2);
    func('A', 12.4);
    func(100, "Testing");
    func(2000, std::string{"Frank"});
    func(p1, p2);

    // swap function
    cout << "---------------------------" << endl;
    int x{200};
    int y{300};
    func(x, y);
    swap(x, y);
    func(x, y);

    func(p1, p2);
    swap(p1, p2);
    func(p1, p2);

    return 0;
}