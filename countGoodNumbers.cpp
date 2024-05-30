#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>

ll power(ll base, ll exponent, ll m)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exponent = exponent / 2;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m = 1e9 + 7;
    ll n = 4;
    ll ans = 1;
    ans = (power(5, (n + 1) / 2, m) * power(4, n / 2, m)) % m;
    cout << ans << endl;
    return 0;
}