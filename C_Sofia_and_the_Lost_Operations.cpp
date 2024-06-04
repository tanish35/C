// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vll vector<long long>
// #define db double
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define umap unordered_map<int, int>
// #define uset unordered_set<int>
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

//         vi a(n);
//         for (int i = 0; i < n; ++i)
//         {
//             cin >> a[i];
//         }

//         vi b(n);
//         uset b1;
//         for (auto &x : b)
//         {
//             cin >> x;
//             b1.insert(x);
//         }

//         multiset<int> r;
//         for (int i = 0; i < n; ++i)
//         {
//             if (a[i] != b[i])
//                 r.insert(b[i]);
//         }

//         int m;
//         cin >> m;

//         int c = 0;
//         for (int i = 0; i < m; ++i)
//         {
//             int x;
//             cin >> x;

//             if (r.find(x) != r.end())
//             {
//                 r.erase(r.find(x));
//                 if (i == m - 1)
//                     c = 1;
//             }
//             else if (b1.count(x))
//             {
//                 if (i == m - 1)
//                     c = 1;
//             }
//         }

//         if (c && r.empty())
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

void solve()
{
    int n, m;
    cin >> n;
    int modi = 0;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> mp2;
    map<int, int> mp;
    int last_el = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] != a[i])
        {
            modi++;
            mp[b[i]]++;
        }
    }
    int size;
    cin >> size;
    vector<int> d(size);
    for (int i = 0; i < size; i++)
    {
        cin >> d[i];
        mp2[d[i]]++;
        if (i == size - 1)
        {
            last_el = d[i];
        }
    }

    if (modi > size)
    {
        cout << "NO" << endl;
        return;
    }

    if (modi == size)
    {
        if (mp == mp2)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (mp2[it->second] < mp[it->second])
        {
            cout << "NO" << endl;
            return;
        }
    }
    auto fin = mp.find(last_el);
    if (fin->second == 0)
    {

        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
