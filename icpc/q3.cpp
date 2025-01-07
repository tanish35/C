#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, c, d, p, q, y;
        cin >> n >> a >> b >> c >> d >> p >> q >> y;
        ll AtoB = abs(a - b) * p;
        ll AtoC = abs(a - c) * p;
        if (AtoC > y)
        {
            cout << AtoB << endl;
            continue;
        }
    }
}
