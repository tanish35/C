#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n = 2;
        cin >> n;
        vi a(n), b(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll cost = 0;
        for (int i = 0; i < n + 1; i++)
        {
            cin >> b[i];
            if (i != n)
            {
                cost += abs(a[i] - b[i]);
            }
        }
        int c = b[n];
        ll near = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int mi = min(a[i], b[i]);
            int ma = max(a[i], b[i]);
            if (mi < c && ma < c && near > c - ma)
            {
                near = c - ma;
            }
            else if (mi > c && ma > c && near > mi - c)
            {
                near = mi - c;
            }
            else if (mi <= c && ma >= c)
            {
                near = 0;
            }
            if (near == 0)
            {
                break;
            }
        }
        // cout << near << "##" << endl;
        cout << cost + near + 1 << endl;
    }
}