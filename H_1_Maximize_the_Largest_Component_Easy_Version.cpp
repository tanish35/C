
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
#define umaps unordered_map<int, char, custom_hash>

const int MAX_N = 1000000 + 100;

int n, m;
umaps grid[MAX_N];
umap componentId[MAX_N];
int currComponentId;

int dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '.' || componentId[x][y] != -1)
    {
        return 0;
    }

    componentId[x][y] = currComponentId;
    int size = 1;

    size += dfs(x - 1, y);
    size += dfs(x + 1, y);
    size += dfs(x, y - 1);
    size += dfs(x, y + 1);

    return size;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        umap componentSize;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                componentId[i][j] = -1;
            }
        }

        currComponentId = 1;
        int maxSize = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '#' && componentId[i][j] == -1)
                {
                    componentSize[currComponentId] = dfs(i, j);
                    maxSize = max(maxSize, componentSize[currComponentId]);
                    currComponentId++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int extra = 0;
            uset components;

            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '#')
                {
                    components.insert(componentId[i][j]);
                }
                else
                {
                    extra++;
                    if (i > 0 && grid[i - 1][j] == '#')
                    {
                        components.insert(componentId[i - 1][j]);
                    }
                    if (i < n - 1 && grid[i + 1][j] == '#')
                    {
                        components.insert(componentId[i + 1][j]);
                    }
                    if (j > 0 && grid[i][j - 1] == '#')
                    {
                        components.insert(componentId[i][j - 1]);
                    }
                    if (j < m - 1 && grid[i][j + 1] == '#')
                    {
                        components.insert(componentId[i][j + 1]);
                    }
                }
            }

            for (auto it = components.begin(); it != components.end(); ++it)
            {
                extra += componentSize[*it];
            }
            maxSize = max(maxSize, extra);
        }

        for (int j = 0; j < m; j++)
        {
            int extra = 0;
            uset components;

            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == '#')
                {
                    components.insert(componentId[i][j]);
                }
                else
                {
                    extra++;
                    if (i > 0 && grid[i - 1][j] == '#')
                    {
                        components.insert(componentId[i - 1][j]);
                    }
                    if (i < n - 1 && grid[i + 1][j] == '#')
                    {
                        components.insert(componentId[i + 1][j]);
                    }
                    if (j > 0 && grid[i][j - 1] == '#')
                    {
                        components.insert(componentId[i][j - 1]);
                    }
                    if (j < m - 1 && grid[i][j + 1] == '#')
                    {
                        components.insert(componentId[i][j + 1]);
                    }
                }
            }

            for (auto it = components.begin(); it != components.end(); ++it)
            {
                extra += componentSize[*it];
            }
            maxSize = max(maxSize, extra);
        }

        cout << maxSize << endl;
    }

    return 0;
}
