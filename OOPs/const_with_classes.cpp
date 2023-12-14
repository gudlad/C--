#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Using constant keyword with classes:
- When a class is made constant it's attributes can't be changed.
- Static members of the class can also be declared as constant.
- Constant members can be initialized only at the time of declaration.
- Constant members can be used to declare constant objects.
*/

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    string get_name() const // making sure to compiler that this method at any cost won't change obj's attributes by specifying const;
    {                       // even though this method don't modify obj but without using const compiler won't allow us to call this method.
        return name;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    Player();
    Player(string name);
    Player(string name, int health, int xp);
};

Player::Player() : Player{"None", 0, 0} {}
Player ::Player(string name) : Player{name, 0, 0} {}
Player::Player(string name, int health, int xp) : name(name), health(health), xp(xp) {}

void display(const Player &p)
{
    cout << p.get_name() << endl;
}
int main()
{
    const Player villain{"Villain", 100, 55};
    // er: villain.set_name("super villain");
    // er: villain.get_name();  //! even though get_name() doesn't change the obj's property there is a possibility so compiler gives error so use const keyword at that method;
    display(villain);

    Player Hero{"hero", 1, 1};
    cout << Hero.get_name() << endl;
    Hero.set_name("Super Man");
    display(Hero);
    return 0;
}