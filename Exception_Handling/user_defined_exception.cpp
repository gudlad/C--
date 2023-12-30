#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

class DivideByZeroException
{
};

class NegativeValueException
{
};

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw DivideByZeroException();
    if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main()
{
    try
    {
        double miles_gallon = calculate_mpg(10, 20);
        cout << miles_gallon << endl;
        miles_gallon = calculate_mpg(10, 0);
        miles_gallon = calculate_mpg(-1, 20);
    }
    catch (const DivideByZeroException &er)
    {
        cerr << "Dvd by zero." << endl;
    }
    catch (const NegativeValueException &er)
    {
        cerr << "Negative value error" << endl;
    }

    cout << "Exiting.." << endl;
    return 0;
}