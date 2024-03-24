#include <iostream>
using namespace std;
class Hero
{
    int health;
    char level;

public:
    // ampersand sign is used to prevent the copy constructor from calling itself as it passes the value by reference
    Hero(Hero &h)
    {
        health = h.health;
        level = h.level;
        cout << "Copy constructor called" << endl;
    }
    Hero()
    {
        cout << "Default constructor called" << endl;
    }
    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    void setHealth(int h)
    {
        health = h;
    }
    void setLevel(char l)
    {
        level = l;
    }
    void getHealth()
    {
        cout << "Health: " << health << endl;
    }
    void getLevel()
    {
        cout << "Level: " << level << endl;
    }
};

int main()
{
    Hero me(100, 'S');
    Hero you(me);
    // you.getHealth();
    // you.getLevel();
}
