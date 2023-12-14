#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Static Class Members:
- A single data member that belongs to the class, not the objects
- Useful to store class -wide information
- Class function can be declared as static independent of any objects and called using class name;

*/

//! the class definitions are kept in .hpp or .h file in c++ project and implementations in .cpp file.
class Player
{
private:
    static int num_players; /* static member; ! we can't initialize it here */
    string name;
    int health;
    int xp;

public:
    static int get_num_players();
    string get_name()
    {
        return name;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    Player();
    Player(string name);
    Player(string name, int health, int xp);
    ~Player();
};

//! the below lines are usually placed in .cpp file in c++ project.
int Player::num_players = 0;
int Player::get_num_players() // static method can have access to only static data members;
{
    return num_players;
}

Player::Player() : Player{"None", 0, 0} {}
Player ::Player(string name) : Player{name, 0, 0} {}
Player::Player(string name, int health, int xp) : name(name), health(health), xp(xp)
{
    num_players++;
}
Player::~Player()
{
    num_players--;
}

//! these line done in main.cpp
void display_active_players() //! helper function
{
    cout << "Active players " << Player::get_num_players() << endl;
}
int main()
{
    display_active_players();
    Player hero("hero");
    display_active_players();
    {
        Player frank{"Frank"};
        display_active_players();
    }
    display_active_players();
    Player *enemy = new Player("Enemy");
    display_active_players();
}