#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    while (x--)
    {
        int m, n;
        cin >> m >> n;
        int t = n + m;
        vi a(t + 1), b(t + 1);
        for (int i = 0; i < t + 1; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < t + 1; i++)
        {
            cin >> b[i];
        }
        int skill = 0;
        int flag = 0;
        umap mp;
        uset program;
        uset test;
        int dilem = 3;
        int max = 0;
        int odd = t + 2;
        for (int i = 0; i < t + 1; i++)
        {
            if (a[i] > b[i])
            {
                if (m > 0)
                {
                    m--;
                    skill += a[i];
                    program.insert(i);
                    mp[i] = a[i];
                }
                else if (m == 0 && flag != 1)
                {
                    dilem = 0;
                    max = a[i];
                    skill += b[i];
                    odd = i;
                    flag = 1;
                    mp[i] = b[i];
                }
                else
                {
                    n--;
                    skill += b[i];
                    test.insert(i);
                    mp[i] = b[i];
                }
            }
            else if (a[i] < b[i])
            {
                if (n > 0)
                {
                    n--;
                    skill += b[i];
                    test.insert(i);
                    mp[i] = b[i];
                }
                else if (n == 0 && flag != 1)
                {
                    dilem = 1;
                    max = b[i];
                    skill += a[i];
                    odd = i;
                    flag = 1;
                    mp[i] = a[i];
                }
                else
                {
                    m--;
                    skill += a[i];
                    program.insert(i);
                    mp[i] = a[i];
                }
            }
        }
        for (int i = 0; i < t + 1; i++)
        {
            int p = 0;
            skill -= mp[i];
            if (i != odd)
            {
                if (dilem == 0)
                {
                    if (program.find(i) != program.end())
                    {
                        skill -= mp[odd];
                        skill += max;
                        p = 1;
                    }
                }
                else
                {
                    if (test.find(i) != test.end())
                    {
                        skill -= mp[odd];
                        skill += max;
                        p = 1;
                    }
                }
            }
            cout << skill << " ";
            skill += mp[i];
            if (p == 1)
            {
                skill -= max;
                skill += mp[odd];
            }
        }
        cout << endl;
    }
}