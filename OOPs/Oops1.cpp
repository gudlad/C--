#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    // overloaded constructors
    Player()
    {
        name = "";
        health = 0;
        xp = 0;
        cout << "constructor called" << endl;
    }
    Player(std::string name);
    Player(std::string name, int health, int xp);

    // destructor
    ~Player()
    {
        cout << "destructor called." << endl;
    }

    void set_name(std::string value);
};

Player::Player(std::string name, int health, int xp) // methods and constructors can also be declared outside class using :: scope resolution operator
{
    cout << "constructor 2 called" << endl;
}

void Player::set_name(std::string value)
{
    name = value;
}

int main()
{
    Player frank;
    Player *p1 = new Player("max", 500, 2000);
    delete p1;
    return 0;
}