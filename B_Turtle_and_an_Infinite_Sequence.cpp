#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll l = max((ll)0, n - m), r = n + m;
        ll ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            bool lBit = (l & (1 << i)) ? true : false;
            bool rBit = (r & (1 << i)) ? true : false;
            bool lShift = (l >> (i + 1)) == (r >> (i + 1));
            if (lBit || rBit || !lShift)
            {
                ans = ans + (ll)(pow(2, i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}