#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int s = 0;
        if (a % b == 0)
        {
            s = a / b;
        }
        else
        {
            s = (a / b) + 1;
        }
        if (s + c >= a)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}