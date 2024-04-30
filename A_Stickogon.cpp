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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            if (mp[a[i]] == 3)
            {
                ans++;
                mp[a[i]] = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}