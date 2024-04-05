#include <iostream>
using namespace std;
class Animal
{
public:
    int age;
    int weight;

public:
    void bark()
    {
        cout << "Animal bark" << endl;
    }
};

class Human
{
public:
    string name;
    int age;

public:
    void speak()
    {
        cout << "Human speak" << endl;
    }
};

class Hybrid : public Animal, public Human
{
public:
};

int main()
{
}