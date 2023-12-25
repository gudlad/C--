#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
!Abstract Class;
-can't instantiate objects
-these classes are used as base classes in inheritance hierarchies
-contains atleast one pure virtual function.

!Pure Virtual Functions;
-Used to make a class Abstract
- The derived class must provide body to the Pure virtual function otherwise it also become abstract.

*/
class Shape // Abstract Base Class
{
private:
    // attributes common to all classes
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {}
};

class Open_shape : public Shape // Abstract class
{
public:
    virtual ~Open_shape() {}
};

class Line : public Open_shape
{
public:
    virtual void draw()
    {
        cout << "Drawing Line" << endl;
    }
    virtual void rotate()
    {
        cout << "Rotate line 90 degrees" << endl;
    }
    virtual ~Line()
    {
    }
};

int main()
{
    // static binding only
    Line l;
    l.draw();
    return 0;

    // dynamic polymorphism
    Shape *ptr = new Line{};
    ptr->draw();
    ptr->rotate();
}