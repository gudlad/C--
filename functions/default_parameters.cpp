#include <iostream>
using namespace std;

void calc_cost(double baseCost, double tax_rate = 0.06, double shipping = 3.50);
void greeting(string name, string prefix = "Mr.", string suffix = "");

void calc_cost(double baseCost, double tax_rate, double shipping)
{
    std::cout << baseCost << " " << tax_rate << " " << shipping << endl;
}
void greeting(string name, string prefix, string suffix)
{
    cout << "Hello " << prefix + " " << name << " " + suffix << endl;
}

int main(int argc, char const *argv[])
{
    calc_cost(1000, 0.1);
    calc_cost(2000);
    greeting("Glen", "Dr.", "MD");
    greeting("Frank Muller", "Dr.");
    greeting("Will Smith");
    return 0;
}
