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
#define umap unordered_map<int, int, custom_hash>
#define uset unordered_set<int, custom_hash>

pair<int, int> find_center(const vector<string> &grid, int n, int m)
{
    vector<int> x_coords;
    vector<int> y_coords;

    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (grid[x][y] == '#')
            {
                x_coords.push_back(x + 1);
                y_coords.push_back(y + 1);
            }
        }
    }

    sort(x_coords);
    sort(y_coords);

    int median_x = x_coords[x_coords.size() / 2];
    int median_y = y_coords[y_coords.size() / 2];

    return {median_x, median_y};
}

int main()
{
    int t;
    cin >> t;
    vector<pair<int, vector<string>>> test_cases;

    for (int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[j];
        }
        test_cases.push_back({n, grid});
    }

    for (const auto &test_case : test_cases)
    {
        int n = test_case.first;
        const vector<string> &grid = test_case.second;
        pair<int, int> result = find_center(grid, n, grid[0].size());
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
