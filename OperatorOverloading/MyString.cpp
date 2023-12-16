#include <iostream>
#include <cstring>
#include "MyString.hpp"

using std::cin;
using std::cout;
using std::endl;

// ==
bool MyString::operator==(const MyString &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
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
