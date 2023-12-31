#include <iostream>
#include <iomanip>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void ruler()
{
    cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890" << endl
         << endl;
}

struct City
{
    string name;
    long population;
    double cost;
};

struct Country
{
    string name;
    std::vector<City> cities;
};

struct Tours
{
    string name;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{
        "Tour Ticket Prices from Miami",
        {
            {"Colombia",
             {
                 {"Bogota", 87800, 400.981212},
                 {"Medellin", 2450000, 300.50},
                 {"Cartagena", 971592, 550.7545},
             }},
            {"Brazil",
             {
                 {"Rio de Janeiro", 6710000, 700.251},
                 {"Sao Paulo", 12180000, 600.302},
                 {"Brasilia", 3050000, 450.9033},
             }},
            {"Chile",
             {
                 {"Santiago", 4950000, 500.80456},
                 {"Valparaiso", 315000, 350.6067},
                 {"La Serena", 260000, 420.40899},
             }},
            {"Argentina",
             {
                 {"Buenos Aires", 2890000, 550.2023},
                 {"Cordoba", 1423000, 480.7534},
                 {"Rosario", 1340000, 520.905443},
             }},
        }};

    const int total_width{70};
    const int f1_width{20}; // country name
    const int f2_width{20}; // city name
    const int f3_width{15}; // population
    const int f4_width{15}; // cost
    ruler();
    int title_length = tours.name.length();

    cout << std::setw((total_width - title_length) / 2)
         << "" // if we don't provide anything here it will apply to tours.name
         << tours.name
         << endl
         << endl;

    cout << std::setw(f1_width)
         << std::left
         << "Country"
         << std::setw(f2_width)
         << std::left
         << "City"
         << std::setw(f3_width)
         << std::right
         << "Population"
         << std::setw(f4_width)
         << std::right
         << "Price"
         << endl;

    cout << std::setw(total_width)
         << std::setfill('-')
         << "" //  if we don't provide any thing here it will apply to next value.
         << endl;

    cout << std::setfill(' ');

    for (auto country : tours.countries) // loop through countries vector
    {
        for (int i = 0; i < country.cities.size(); i++)
        {
            cout << std::setw(f1_width) << std::left << (i == 0 ? country.name : "")
                 << std::setw(f2_width) << std::left << country.cities.at(i).name
                 << std::setw(f3_width) << std::right << country.cities.at(i).population
                 << std::setw(f3_width) << std::right << std::setprecision(2) << std::fixed << country.cities.at(i).cost
                 << endl;
        }
    }
    cout << endl
         << endl;
    return 0;
};