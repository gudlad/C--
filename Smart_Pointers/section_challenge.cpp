#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Test
{
private:
    int data;

public:
    Test() : data{0}
    {
        cout << "Test constructor" << endl;
    }
    Test(int data) : data{data}
    {
        cout << "Test constructor 2" << endl;
    }
    int getData()
    {
        return data;
    }
    ~Test() { cout << "Test destructor" << endl; }
};

// function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
// vec_ptr -> vector of shared pointers -> each shared pointer -> Trust;

void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = std::move(make()); // unique pointer can't be assigned or copied so use move semantic.
    cout << "How many data points do you want to enter :" << endl;
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    int temp;
    for (int i = 1; i <= num; i++)
    {
        cout << "enter data point :" << i << ":" << endl;
        cin >> temp;
        vec.push_back(std::make_shared<Test>(temp));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    cout << "Displaying vector data :" << endl;
    for (const auto &i : vec)
    {
        cout << i->getData() << "\t";
    }
}