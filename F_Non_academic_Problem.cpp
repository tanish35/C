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

// Print function without newline
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
void print_helper(const unordered_set<T, custom_hash> &us)
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
void print_helper(const unordered_map<K, V, custom_hash> &um)
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

map<pair<int, int>, ll> edgeMap;
ll timer;

pair<ll, ll> dfs(ll node, vector<vector<ll>> &graph, vector<ll> &dt, ll parent)
{
    if (dt[node] != -1)
    {
        return {dt[node], 0};
    }

    timer++;
    dt[node] = timer;

    ll et = dt[node], sts = 1;

    for (auto &neighbor : graph[node])
    {
        if (neighbor == parent)
            continue;
        pair<ll, ll> result = dfs(neighbor, graph, dt, node);
        ll ent = result.first, sizeOfSubtree = result.second;

        sts += sizeOfSubtree;

        if (ent <= dt[node])
        {
            et = min(et, ent);
        }
        else
        {
            edgeMap[{node, neighbor}] = sizeOfSubtree;
        }
    }

    dt[node] = et;
    return {et, sts};
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll nn, ne;
        cin >> nn >> ne;

        vector<vector<ll>> graph(nn);

        while (ne--)
        {
            ll node1, node2;
            cin >> node1 >> node2;
            node1--;
            node2--;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        edgeMap.clear();
        timer = 0;
        vector<ll> dt(nn, -1);
        pair<ll, ll> result = dfs(0, graph, dt, -1);

        ll minEdges = nn * (nn - 1) / 2;
        for (auto &entry : edgeMap)
        {
            ll sts = entry.second, cs = nn - entry.second;
            minEdges = min(minEdges, (sts * (sts - 1) + (cs * (cs - 1))) / 2);
        }

        cout << minEdges << endl;
    }
    return 0;
}
