#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll p[200010], s[200010];
ll a[200010];
ll now[20];
ll n, q;
ll tr(string s)
{
    ll res = 0;
    if (s[0] == 'R')
        res++;
    if (s[1] == 'R')
        res++;
    if (s[0] == 'G')
        res += 2;
    if (s[1] == 'G')
        res += 2;
    if (s[0] == 'B')
        res += 4;
    if (s[1] == 'B')
        res += 4;
    if (s[0] == 'Y')
        res += 8;
    if (s[1] == 'Y')
        res += 8;
    return res;
}
vector<ll> xd;
void work()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        p[i] = 0;
        s[i] = mod;
        string x;
        cin >> x;
        a[i] = tr(x);
    }
    memset(now, 0, sizeof(now));
    for (int i = 1; i <= n; i++)
    {
        for (auto j : xd)
        {
            if (now[j] != 0 && ((j & a[i]) != 0) && j != a[i])
            {
                p[i] = max(p[i], now[j]);
            }
        }
        now[a[i]] = i;
    }
    memset(now, 0, sizeof(now));
    for (int i = n; i >= 1; i--)
    {
        for (auto j : xd)
        {
            if (now[j] != 0 && ((j & a[i]) != 0) && j != a[i])
                s[i] = min(s[i], now[j]);
        }
        now[a[i]] = i;
    }
    while (q--)
    {
        ll i, j;
        cin >> i >> j;
        if (a[i] & a[j])
        {
            cout << abs(i - j) << '\n';
            continue;
        }
        ll ans = mod;
        if (p[i] != 0)
            ans = min(ans, abs(i - p[i]) + abs(j - p[i]));
        if (p[j] != 0)
            ans = min(ans, abs(i - p[j]) + abs(j - p[j]));
        if (s[i] != mod)
            ans = min(ans, abs(i - s[i]) + abs(j - s[i]));
        if (s[j] != mod)
            ans = min(ans, abs(i - s[j]) + abs(j - s[j]));
        if (ans == mod)
            cout << "-1\n";
        else
            cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    xd.push_back(3);
    xd.push_back(5);
    xd.push_back(9);
    xd.push_back(6);
    xd.push_back(10);
    xd.push_back(12);
    int T;
    cin >> T;
    while (T--)
    {
        work();
    }
    // system("pause");
}