#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<int, int, custom_hash>
#define uset unordered_set<int, custom_hash>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vi b(n);
        uset b1;
        for (auto &x : b)
        {
            cin >> x;
            b1.insert(x);
        }

        multiset<int> r;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
                r.insert(b[i]);
        }

        int m;
        cin >> m;

        int c = 0;
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;

            if (r.find(x) != r.end())
            {
                r.erase(r.find(x));
                if (i == m - 1)
                    c = 1;
            }
            else if (b1.count(x))
            {
                if (i == m - 1)
                    c = 1;
            }
        }

        if (c && r.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
