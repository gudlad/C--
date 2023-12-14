#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
!Overloading the COPY assignment Operator for MyString Class: (works with l-value references)

MyString s1 {"Frank"};
MyString s3 {"ram"};
MyString s2=s1  //? NOT assignment same as MyString s2{s1}
s3=s1;          //? NOW this is assignment , c++ provides default implementation to = and calls the shallow copy constructor which is not suitable for class with raw pointer, so we overload the default implementation of = to provide deep copy constructor.
!Syntax:
Type& Type::operator=(const Type &rhs); //? the return type is reference of the obj MyString&.

? Chaining of assignments (also known as cascading): Returning a reference allows you to chain multiple assignments together. For example, you can write expressions like a = b = c, and each assignment returns a reference to the modified object.

? MyString a{"Hello"};
? MyString b;
? MyString c;

? a = b = c;  // Chaining assignments

!after this:
s2=s1, s2=s1 equivalent to s2.operator=(s1) and provides deep copy;

*/
class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    ~MyString();
    void display() const;
    int get_length() const;
    const char *get_str() const;
    //! over loading the = operator
    MyString &operator=(const MyString &rhs);
};

MyString &MyString::operator=(const MyString &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

MyString::MyString() : str(nullptr)
{
    str = new char[1];
    *str = '\0';
}
MyString::MyString(const char *s) : str(nullptr)
{
    if (s == nullptr)
        MyString();
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString &source)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

MyString::~MyString()
{
    delete[] str;
}

void MyString::display() const
{
    cout << str << ":" << get_length() << endl;
}

int MyString::get_length() const
{
    return strlen(str);
}

const char *MyString::get_str() const
{
    return str;
}

int main()
{
    MyString a{"Hello"};
    a.display();
    MyString b;
    b = a; // copy assignment, after overloading --> b.operator=(a) deep copy
    b.display();
    b = "This is a test"; // Here 2 things happens
                          // first the conversion constructor is called which converts the "This is test" c style string into temporary MyString object (only in case of overloading)
                          // after that overloading --> b.operator=(temp obj) is done.
    b.display();
}