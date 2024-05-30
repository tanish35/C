#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vi> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == 1)
                cnt++;
        }
        if (cnt < n - cnt)
        {
            for (int i = 0; i < n; i++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += grid[i][j] * pow(2, m - j - 1);
        }
    }
    cout << ans;
    return 0;
}