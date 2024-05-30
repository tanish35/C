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
    vi asteroids = {-5, -10, 5};
    vi ans;
    int n = asteroids.size();
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || asteroids[i] > 0)
            ans.push_back(asteroids[i]);
        else
        {
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i]))
                ans.pop_back();
            if (ans.empty() || ans.back() < 0)
                ans.push_back(asteroids[i]);
            else if (ans.back() == abs(asteroids[i]))
                ans.pop_back();
        }
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}