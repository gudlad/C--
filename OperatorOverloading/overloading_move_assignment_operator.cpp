#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
!Overloading move assignment operator for MyString class:
- The copy assignment operator we overloaded in previous program works with L-value references.
- The move assignment operator works with R-value references.
- ex;
MyString s1;
s1 = MyString {"Frank"}     //! move assignment (MyString {"Frank"} has no name)
                            ? move operator= called.

s1="Frank";  //? move operator= called. if move assignment operator not is not provided c++ will use copy assignment operator by default.

-syntax;
MyString& MyString::operator=(MyString&& rhs);

- if we have pointer we should overload the move assignment operator for efficiency.

*/
class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();
    void display() const;
    int get_length() const;
    const char *get_str() const;
    //! overloading operators.
    MyString &operator=(MyString &&rhs);
    MyString &operator=(const MyString &rhs);
};

MyString::MyString() : str(nullptr) // constructor 1
{
    cout << "using default constructor" << endl;
    str = new char[1];
    *str = '\0';
}
MyString::MyString(const char *s) : str(nullptr) // overloaded constructor 2
{
    cout << "using overloaded constructor" << endl;
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

MyString::~MyString() // destructor
{
    if (str == nullptr)
        cout << "calling destructor for MyString nullptr" << endl;
    else
    {
        cout << "Calling destructor for MyString " << str << endl;
    }
    delete[] str;
}

//! overloaded operators.------------------------------------------------------------------->

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

MyString &MyString::operator=(const MyString &rhs) // copy assignment
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
    MyString a{"Hello"};
    a = MyString{"Hola"}; // overloaded constructor -> move assignment
    a = "Bonjour";        // overloaded constructor -> move assignment

    MyString empty;
    MyString larry{"Larry"}; // overloaded constructor
    MyString stooge{larry};  // copy constructor
    MyString stooges;

    empty = stooge; // copy assignment operator stooge l-value

    empty = "funny"; // move assignment operator "funny" is r-value

    return 0;
}