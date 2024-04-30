#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, a, b;
        cin >> m >> a >> b;
        if (a * 2 > b)
        {
            cout << (m / 2) * b + (m % 2) * a << endl;
        }
        else
        {
            cout << m * a << endl;
        }
    }
}