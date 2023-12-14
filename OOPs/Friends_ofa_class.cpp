#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Friend of a Class:
- A function or class that has access to all public,private,private class members.
- And, that function of a class or stand alone function is not a member of the class it is accessing.
- Can be non-member function or member of another class
- Another class can have access to private class members.
*/
#include <iostream>
using namespace std;

class Player; //! Forward declaration to let the compiler know that Player class exists
class Coach
{
public:
    void display_player(Player &p);
};

class Teacher
{
public:
    void display_player(Player &p);
};

class Player
{
private:
    friend void display_player(Player &p);        // Friend function declaration
    friend void Coach::display_player(Player &p); // Friend function declaration
    friend class Teacher;                         // Friend class declaration

    string name;
    int health;
    int xp;

public:
    Player();
    Player(string name);
    Player(string name, int health, int xp);
};

Player::Player() : Player{"None", 0, 0} {}
Player::Player(string name) : Player{name, 0, 0} {}
Player::Player(string name, int health, int xp) : name(name), health(health), xp(xp) {}

void display_player(Player &p)
{
    cout << p.name << endl;
    cout << p.health << endl;
    cout << p.xp << endl;
}

void Coach::display_player(Player &p)
{
    cout << p.name << endl;
    cout << p.health << endl;
    cout << p.xp << endl;
}

void Teacher::display_player(Player &p)
{
    cout << p.name << endl;
    cout << p.health << endl;
    cout << p.xp << endl;
}

int main()
{
    Player p{"Hero", 9, 0};
    display_player(p);

    Coach coach;
    coach.display_player(p);

    Teacher teacher;
    teacher.display_player(p);

    return 0;
}
