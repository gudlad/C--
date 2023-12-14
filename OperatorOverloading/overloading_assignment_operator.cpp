#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
/*
Operator Overloading:
- Allows user defined types to behave similar to built-in types
- can make code more readable and writable
- Not done automatically (except for =)they must be explicitly defined.
*/

class MyString
{
private:
    char *str; // c style string -OR- pointer to char[] that hold C-style string
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    ~MyString();
    void display() const;
    int get_length() const;
    const char *get_str() const;
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
    // const char *str = "Guru";
    // int i = 0;
    // while (str[i] != '\0')
    // {
    //     cout << str[i];
    //     i++;
    // }
    MyString empty;
    MyString Larry{"Larry"};
    MyString Stooge{Larry};
    empty.display();
    Larry.display();
    Stooge.display();
    return 0;
}