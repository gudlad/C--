#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

/*
?? Unary operators as non-member methods or Global functions(++,--,-,!)
ReturnType operatorOp(Type& obj);
Number operator--(const Number& obj);
Number operator++(Number &obj);     //! pre-increment
Number operator++(Number &obj);  //! post-increment
bool operator!(const Number& obj) const;

!ex;
Number n1 {199};
Number n2=-n1;   operator-(n1)
n2=++n1;         operator++(n1)
n2=n1++;         operator++(n1,int)

?? if non member function we very often need access to private members of the object
?? so often these non-member methods are defined as friend functions of class, alternatively we can use get methods also.
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
    void display() { cout << str << endl; }
    friend MyString operator-(const MyString &lhs);
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
MyString operator-(const MyString &lhs)
{
    char *buff = new char[std::strlen(lhs.str) + 1];
    std::strcpy(buff, lhs.str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    MyString temp{buff};
    delete[] buff;
    return temp;
}

int main()
{
    cout << "unary operator non member methods:" << endl;
    MyString larry{"Larry"};
    MyString moe{"Moe"};
    MyString larry2 = -larry;
    larry2.display();
    return 0;
}