#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

/*
?? Unary operators as member methods(++,--,-,!)
ReturnType Type::operatorOp();
Number Number::operator--();
Number Number::operator++();     //! pre-increment
Number Number::operator++(int);  //! post-increment
bool Number::operator!() const;

!ex;
Number n1 {199};
Number n2=-n1;   n1.operator-()
n2=++n1;         n1.operator++()
n2=n1++;         n1.operator++(int)

!Note:
These method return new object by value not reference.
These objects have empty parameters list because the object we work with is referred to by the this pointer
this pointer points to the single obj we're operating on.
*/

class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *str);
    MyString(MyString &&source);
    ~MyString();
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);

    MyString operator-() const;
    void display()
    {
        cout << str << endl;
    }
};

MyString::MyString() : str(nullptr)
{
    str = new char[1]; // allocating memory for char array with size 1;
    *str = '\0';
}
MyString::MyString(const char *s) : str(nullptr) // overloaded constructor
{
    if (s == nullptr)
        MyString();
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::~MyString()
{
    delete[] str;
}

// -
MyString MyString::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    MyString temp{buff};
    delete[] buff;
    return temp;
}

int main()
{
    cout << "unary operator overloading class base:" << endl;
    MyString larry{"Larry"};
    MyString moe{"Moe"};
    MyString larry2 = -larry;
    larry2.display();
    return 0;
}