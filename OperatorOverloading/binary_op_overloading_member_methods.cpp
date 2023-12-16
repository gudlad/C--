#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

/*
?? Binary operators as member methods(+,-,==,!=,<,> etc.)

Number Number::operator+(const &Number rhs) const;
Number Number::operator-(const &Number rhs) const;
bool Number::operator==(const &Number rhs) const;
bool Number::operator<(const &Number rhs) const;

!Ex;
Number n1{199},n2{200}
Number n3=n1+n2   n1.operator+(n2)
n3=n1-n2          n1.operator-(n2)
if(n1==n2)        n2.operator==(n2)

!Note:
These method return new object by value not reference.
These objects have empty parameters list because the object we work with is referred to by the this pointer
This Pointer points to the obj on the LHS of the operator

!!Note:
in class member based overloading.
MyString larry{"Larry"};
MyString curt {"Curt"};
MyString moe {"Moe"}
MyString result=larry+curt;
result= moe + "is also a string"  //! move.operator+("is also a string") this works.
result= "some string"+ moe        //! "some string".operator+(moe)       this will not work as lhs should be an object of type MyString.

?? To overcome these we use the Non member operator overloading.
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

    MyString operator+(const MyString &rhs) const;
    bool operator==(const MyString &rhs) const;
    void display() const { cout << str << endl; }
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
bool MyString::operator==(const MyString &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// concatenate
MyString MyString::operator+(const MyString &rhs) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
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
    cout << "binary operator overloading class base:" << endl;
    MyString larry{"Larry"};
    MyString moe{"Moe"};

    cout << (larry == moe) << endl;

    MyString result = larry + moe;
    result = larry + "Grand";
    // result = "Grand" + moe; //! error.
    result.display();

    return 0;
}