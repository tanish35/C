#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define sort(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<int>())
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
template <typename T>
void prints_helper(const T &t)
{
    cout << t;
}

template <typename T, typename... Args>
void prints_helper(const T &t, const Args &...args)
{
    cout << t;
    prints_helper(args...);
}

template <typename... Args>
void prints(const Args &...args)
{
    prints_helper(args...);
}

// Print function with newline

template <typename T>
void print_helper(const T &t)
{
    cout << t;
}

template <typename T, typename... Args>
void print_helper(const T &t, const Args &...args)
{
    cout << t;
    print_helper(args...);
}

template <typename... Args>
void print(const Args &...args)
{
    print_helper(args...);
    cout << endl;
}
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
#define umap unordered_map<int, db, custom_hash>
#define uset unordered_set<int, custom_hash>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vll d(k + 1);
        vll t(k + 1);
        d[0] = 0;
        t[0] = 0;
        for (int i = 1; i < k + 1; i++)
        {
            cin >> d[i];
        }
        for (int i = 1; i < k + 1; i++)
        {
            cin >> t[i];
        }
        for (int i = 0; i < q; i++)
        {
            int query;
            cin >> query;
            int l = 0;
            int r = k;
            while (l <= r)
            {
                // print(r);
                int mid = (l + r) / 2;

                if (d[mid] > query)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // print(r);
            if (d[r] == query)
            {
                prints(t[r], " ");
                continue;
            }
            ll ans = -1;
            ans = (query - d[r]) * (t[r + 1] - t[r]) / (d[r + 1] - d[r]) + t[r];
            prints(ans, " ");
        }
        cout << endl;
    }
    return 0;
}