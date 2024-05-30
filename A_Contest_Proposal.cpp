#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                int ptr = i;
                a.pop_back();
                a.push_back(b[i]);
                sort(a.begin() + i, a.end());
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}