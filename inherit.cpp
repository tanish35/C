#include <iostream>
using namespace std;

class Human
{
private:
    int age;
    int height;
    int weight;

public:
    void getAge()
    {
        cout << this->age << endl;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
    void setAge(int a)
    {
        this->age = a;
    }
    void getWeight()
    {
        cout << this->weight << endl;
    }
    void getHeight()
    {
        cout << this->height << endl;
    }
    void setHeight(int h)
    {
        this->height = h;
    }
};

class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Sleeping" << endl;
    }
};

class Female : public Human
{
public:
};

int main()
{
    Male ml;
    Female fm;
    ml.setHeight(30);
    ml.getHeight();
    fm.getHeight();

    ml.setWeight(50);
    ml.getWeight();
    fm.getWeight();
}