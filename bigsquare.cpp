#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long n;
        cin >> n;
        long s = 0;
        for (int j = 0; j < n; j++)
        {
            long a;
            cin >> a;
            s += a;
        }
        double x = sqrt(s);
        if (x == floor(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
