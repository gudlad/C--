#include <iostream>
#include <memory>

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
    ~Test() { cout << "Test destructor" << endl; }
};

void my_deleter(Test *ptr) // the my_deleter method receives raw pointer of type Test
{
    cout << "Using my custom function deleter" << endl;
    delete ptr;
}

int main()
{
    //! using a function.
    {

        std::shared_ptr<Test> ptr1{new Test{0}, my_deleter};
    }
    // when the pointer is about get deleted it has to free the memory so it calls the my_deleter function and we have complete control over it.

    //! using lambda expression ( creates a closure object )
    {

        std::shared_ptr<Test> ptr2{new Test{1000},
                                   [](Test *ptr)
                                   {
                                       cout << "using my custom lambda deleter" << endl;
                                       delete ptr;
                                   }};
    }

    return 0;
}