#include <iostream>

//? required for vector
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> scores(3);
    int value{0};
    cout << "enter an elements" << endl;
    while (value != 3)
    {
        int temp{0};
        cin >> temp;
        scores.push_back(temp); // add elements at back of vector-> 0 0 0  value value value;
        value++;
    }
    cout << scores.size() << endl;
    cout << scores.at(0);
    return 0;
}
