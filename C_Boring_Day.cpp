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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        vll a(n);
        forn(i, n)
        {
            cin >> a[i];
        }
        ll win = 0;
        ll sum = 0;
        ll p = 0;
        ll q = 0;
        while (q < n)
        {
            sum += a[q];
            while (sum > r && p <= q)
            {
                sum -= a[p];
                p++;
            }
            if (sum >= l && sum <= r)
            {
                win++;
                sum = 0;
                p = q + 1;
            }
            q++;
        }
        print(win);
    }
    return 0;
}