#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vll vector<long long>
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<int>())
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
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
    cout << t << " ";
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
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vll a(n);
        forn(i, n) cin >> a[i];
        ll low = a[0] - x, high = a[0] + x;
        ll ans = 0;
        forsn(i, 1, n)
        {
            ll newLow = a[i] - x, newHigh = a[i] + x;
            if (newLow > low && newHigh < high)
            {
                ans++;
                low = newLow;
                high = newHigh;
            }
            else
            {
                low = max(low, newLow);
                high = min(high, newHigh);
                if (low > high)
                {
                    ans++;
                    low = newLow;
                    high = newHigh;
                }
            }
        }
        print(ans);
    }
    return 0;
}