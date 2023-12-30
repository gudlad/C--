#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    if (miles < 0 || gallons < 0)
        throw std::string{"Negative value error"};
    return static_cast<double>(miles) / gallons;
}

int main()
{
    try
    {
        double miles_gallon = calculate_mpg(10, 20);
        cout << miles_gallon << endl;
        miles_gallon = calculate_mpg(-1, 20);
        miles_gallon = calculate_mpg(10, 0);
    }
    catch (int &er)
    {
        cerr << "Dvd by zero." << endl;
    }
    catch (std::string &er)
    {
        cerr << "Negative value error" << endl;
    }
    catch (...) // can handle any exception.
    {
        cerr << "Unknown exception caught.\n";
    }
    cout << "Exiting.." << endl;
    return 0;
}

/*
! Note:
- constructors can throw exception if they can't instantiate the class
- destructors should never throw exception as it leads to unexpected behaviors.
*/