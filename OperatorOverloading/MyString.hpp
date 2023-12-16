#ifndef _MyString_H_
#define _MyString_H_

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
    MyString operator+(const MyString &rhs) const;
    bool operator==(const MyString &rhs) const;
};

#endif