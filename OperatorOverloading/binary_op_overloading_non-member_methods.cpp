#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

/*
?? Binary operators as member methods(+,-,==,!=,<,> etc.)

Number operator+(const &Number lhs,const &Number rhs);
Number operator-(const &Number lhs,const &Number rhs);
bool operator==(const &Number lhs,const &Number rhs);
bool operator<(const &Number lhs,const &Number rhs);

!Ex;
Number n1{199},n2{200}
Number n3=n1+n2   operator+(n1,n2)
n3=n1-n2          operator-(n1,n2)
if(n1==n2)        operator==(n1,n2)

!!Note:
result= "some string"+ moe    //! OK with non-member functions.
*/

class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    void display() { cout << str << endl; }
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend bool operator==(const MyString &lhs, const MyString &rhs);
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

MyString::MyString(const MyString &source) : str(nullptr) // copy constructor deep copy 3
{
    cout << "using copy constructor" << endl;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

MyString::MyString(MyString &&source) : str(source.str) // move constructor 4
{
    cout << "using move constructor";
    source.str = nullptr;
}

MyString::~MyString()
{
    delete[] str;
}

// ==
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// concatenate
MyString operator+(const MyString &lhs, const MyString &rhs)
{
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp{buff};
    delete buff;
    return temp;
}

MyString &MyString::operator=(MyString &&rhs) // move assignment
{
    cout << "using move assignment" << endl;
    if (this == &rhs)
        return *this;
    delete[] str;        // first release the heap memory
    this->str = rhs.str; // steal the pointer from rhs and assign it to this->str
    rhs.str = nullptr;   // null out rhs pointer
    return *this;        // return the object ref to allow chain assignment
}

MyString &MyString::operator=(const MyString &rhs)
{
    cout << "using copy assignment" << endl;
    if (this == &rhs)
        return *this;

    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

int main()
{
    cout << "binary operator overloading non-member based:" << endl;
    MyString larry{"Larry"};
    MyString moe{"Moe"};

    cout << (larry == moe) << endl;

    MyString result = larry + moe;
    result = larry + "Grand";
    result.display();
    result = "Grand" + moe;
    result.display();
}