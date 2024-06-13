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
#define fi first
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

template <typename T>
void print_helper(const vector<T> &v)
{
    cout << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
            cout << ", ";
        cout << *it;
    }
    cout << "]";
}

template <typename T>
void print_helper(const set<T> &s)
{
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (it != s.begin())
            cout << ", ";
        cout << *it;
    }
    cout << "}";
}

template <typename T>
void print_helper(const unordered_set<T> &us)
{
    cout << "{";
    for (auto it = us.begin(); it != us.end(); ++it)
    {
        if (it != us.begin())
            cout << ", ";
        cout << *it;
    }
    cout << "}";
}

template <typename K, typename V>
void print_helper(const map<K, V> &m)
{
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it != m.begin())
            cout << ", ";
        cout << it->first << ": " << it->second;
    }
    cout << "}";
}

template <typename K, typename V>
void print_helper(const unordered_map<K, V> &um)
{
    cout << "{";
    for (auto it = um.begin(); it != um.end(); ++it)
    {
        if (it != um.begin())
            cout << ", ";
        cout << it->first << ": " << it->second;
    }
    cout << "}";
}

template <typename T, typename... Args>
void print_helper(const T &t, const Args &...args)
{
    print_helper(t);
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

class Disjoint
{
    vector<vector<int>> size;
    vector<vector<pair<int, int>>> par;

public:
    Disjoint(int n, int m)
    {
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            size[i].resize(m, 1);
        }
        par.resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                par[i].push_back({i, j});
            }
        }
    }

    pair<int, int> findpar(pair<int, int> p)
    {
        if (p == par[p.first][p.second])
        {
            return p;
        }
        return par[p.first][p.second] = findpar({par[p.first][p.second].first, par[p.first][p.second].second});
    }

    int findsize(pair<int, int> p)
    {
        return size[p.first][p.second];
    }

    void unionbysize(pair<int, int> u, pair<int, int> v)
    {
        pair<int, int> up = findpar(u);
        pair<int, int> vp = findpar(v);
        if (up == vp)
        {
            return;
        }
        if (size[up.first][up.second] > size[vp.first][vp.second])
        {
            par[vp.first][vp.second] = {up.first, up.second};
            size[up.first][up.second] += size[vp.first][vp.second];
        }
        else
        {
            par[up.first][up.second] = {vp.first, vp.second};
            size[vp.first][vp.second] += size[up.first][up.second];
        }
        return;
    }
};

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        Disjoint ds(n + 1, m + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '#')
                {
                    if (i - 1 >= 0 && v[i - 1][j] == '#')
                    {
                        ds.unionbysize({i, j}, {i - 1, j});
                    }
                    if (j - 1 >= 0 && v[i][j - 1] == '#')
                    {
                        ds.unionbysize({i, j}, {i, j - 1});
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            map<pair<int, int>, int> vis;
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '#')
                {
                    pair<int, int> p = ds.findpar({i, j});
                    vis[p]++;
                }
                else
                {
                    temp++;
                    if (i - 1 >= 0 && v[i - 1][j] == '#')
                    {
                        pair<int, int> p = ds.findpar({i - 1, j});
                        vis[p]++;
                    }
                    if (i + 1 < n && v[i + 1][j] == '#')
                    {
                        pair<int, int> p = ds.findpar({i + 1, j});
                        vis[p]++;
                    }
                }
            }
            for (auto it : vis)
            {
                temp += ds.findsize(it.fi);
            }
            cnt = max(cnt, temp);
        }

        for (int j = 0; j < m; j++)
        {
            int temp = 0;
            map<pair<int, int>, int> vis;
            for (int i = 0; i < n; i++)
            {
                if (v[i][j] == '#')
                {
                    pair<int, int> p = ds.findpar({i, j});
                    vis[p]++;
                }
                else
                {
                    temp++;
                    if (j - 1 >= 0 && v[i][j - 1] == '#')
                    {
                        pair<int, int> p = ds.findpar({i, j - 1});
                        vis[p]++;
                    }
                    if (j + 1 < m && v[i][j + 1] == '#')
                    {
                        pair<int, int> p = ds.findpar({i, j + 1});
                        vis[p]++;
                    }
                }
            }
            for (auto it : vis)
            {
                temp += ds.findsize(it.fi);
            }
            cnt = max(cnt, temp);
        }

        cout << cnt << endl;
    }
    return 0;
}