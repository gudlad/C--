#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

/*
?? Stream operators(<<,>>) overloading using non member methods.(friend methods)
!return a reference to the stream so we can keep using it don't return value.
*/

class Mystring
{
private:
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &os, Mystring &rhs);
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

Mystring::~Mystring()
{
    delete[] str;
}

Mystring::Mystring() : str(nullptr)
{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) : str(nullptr)
{
    if (s == nullptr)
        Mystring();
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
    cout << "using move assignment" << endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void Mystring::display() const
{
    cout << str << ":" << get_length() << endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[] buff;
    return in;
}

int main()
{
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name" << endl;
    cin >> curly;

    cout << "The three stooges are" << larry << "," << moe << "," << curly << endl;

    cout << "\nEnter the three stooges names separated by a space" << endl;
    cin >> larry >> moe >> curly;

    cout << "\nThe three stooges are now " << larry << "," << moe << "," << curly << endl;

    return 0;
}