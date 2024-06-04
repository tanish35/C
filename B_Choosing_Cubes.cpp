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
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        ll favourite = a[f - 1];
        sort(a.begin(), a.end());

        ll g = 0;
        ll e = 0;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == favourite)
            {
                e++;
            }
            else if (a[i] > favourite)
            {
                g++;
            }
        }

        if (g + e <= k)
        {
            cout << "YES" << endl;
        }
        else if (g >= k)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "MAYBE" << endl;
        }
    }
    return 0;
}
