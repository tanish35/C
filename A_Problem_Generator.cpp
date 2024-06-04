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
        int n, m;
        string s;
        cin >> n >> m;
        cin >> s;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 7; i++)
        {
            if (mp[i] < m)
            {
                ans += m - mp[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
