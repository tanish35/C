#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
#define ln "\n"
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define print(x) cout << x << ln

#ifndef ONLINE_JUDGE
#define dbg(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define dbg(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.fi);
    cerr << ",";
    _print(p.se);
    cerr << "}" << ln;
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void solve()
{
    ll n, k;
    cin >> n >> k;
    dbg(n);
    dbg(k);
    v64 v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> vv;
    v64 t;
    for (ll i = 0; i < n; i++)
    {
        ll flag = 0;
        for (ll j = 0; j < 31; j++)
        {
            if ((1ll << j) & k)
            {
                if ((1ll << j) & v[i])
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            vv.pb(v[i]);
            t.pb(i);
        }
    }
    dbg(vv);
    if (vv.size() == 0)
    {
        print("NO");
        return;
    }
    vector<ll> bits(31, 0);
    for (ll i = 0; i < vv.size(); i++)
    {
        for (ll j = 0; j < 31; j++)
        {
            if (((1ll << j) & k) == 0)
            {
                // if(j==0){
                //     dbg(vv[i]);
                //     dbg(vv[i]&(1ll<<j));
                // }
                if ((vv[i] & (1ll << j)) == 0)
                {
                    bits[j] = 1;
                }
            }
        }
    }
    dbg(bits);
    for (ll j = 0; j < 31; j++)
    {
        if (((1ll << j) & (k)) == 0)
        {
            if (bits[j] == 0)
            {
                print("NO");
                return;
            }
        }
    }
    print("YES");
    for (auto i : t)
        cout << i + 1 << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fast_cin();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}