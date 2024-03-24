#include <iostream>
using namespace std;
void update(int &a)
{
    a++;
}

int main()
{
    int c = 10;
    update(c);
    cout << c << endl;
}
