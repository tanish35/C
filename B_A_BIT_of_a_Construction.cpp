#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 1)
        {
            cout << b << endl;
        }
        else
        {
            ll x;
            x = log2(b);
            x = pow(2, x) - 1;
            cout << x << " ";
            b = b - x;
            cout << b << " ";
            a -= 2;
            while (a > 0)
            {
                cout << 0 << " ";
                a--;
            }
            cout << endl;
        }
    }
    return 0;
}