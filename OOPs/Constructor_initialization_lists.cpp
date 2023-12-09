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
    Player();
    Player(std::string name);
    Player(std::string name, int health, int xp);
    void set_name(std::string value);
};

Player::Player(std::string name, int health, int xp)
{
    name = "None"; //! This is only assignment not initialization, before doing this the name string will already be created and assigned with empty string
    health = 0;    //! before this health will already be created and assigned with garbage values.
    xp = 0;        //! before this xp will already be created and assigned with garbage values.
}

//? instead of above constructor use below way of creating constructor
//? Constructor list initializations
Player::Player(std::string name, int health, int xp) : name{"None"}, health{0}, xp{0} //! here when name,health,xp created assigned with None,0 and 0;
{
}

Player::Player(std::string name, int health, int xp) : name("None"), health(0), xp(0) //? both of these syntaxes are same either use { } or () but {} is better.
{
}

Player::Player(std::string) : name{"None"}, health{0}, xp{0}
{
}

Player::Player() : name{"None"}, health{0}, xp{0}
{
}

//? Delegating Constructor to remove code duplication
Player::Player(std::string name_val, int health, int xp) : name{name_val}, health{0}, xp{0}
{
}

Player::Player(std::string value) : Player{value, 0, 0}
{
}

Player::Player() : Player{"None", 0, 0}
{
}

int main()
{
    Player frank;
    Player *p1 = new Player("max", 500, 2000);
    delete p1;
    return 0;
}