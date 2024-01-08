#include <iostream>
#include <cctype>  // for character-based functions which is nothing but c's <ctype.h> library
#include <cstring> // for c-style string functions which is nothing but c's <string.h> library
#include <string>  // c++ string library

using namespace std;

int main()
{
    char first_name[20]{}; //! c style strings and methods of cctype + cstring
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};

    cin >> first_name >> last_name;

    size_t size = strlen(first_name); // size_t is always +ve it can unsigned int,long, double..
    cout << size << endl;

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    cout << "your full name:" << full_name << endl;

    //! get input with spaces
    cin.ignore(); //? consumes the newline character left in previous cin otherwise doesn't able to take input
    cout << "enter full name:" << endl;
    cin.getline(temp, 50); // limit-50
    cout << "your full name:" << temp << endl;

    strcpy(last_name, first_name);
    cout << strcmp(first_name, last_name) << endl;

    std::string target{"lovingly"};
    std::string search{"love"};

    size_t s = target.find(search);

    if (s != std::string::npos)
    {
        std::cout << "found!" << std::endl;
    }
    else
    {
        std::cout << "not found!" << std::endl;
    }
    return 0;
}
