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

    string s = "krrgw";
    string t = "zjxss";
    int maxCost = 19;

    int n = s.size();
    vector<int> cost(n);
    for (int i = 0; i < n; ++i)
    {
        cost[i] = abs(s[i] - t[i]);
    }

    int sum = 0;
    int ans = 0;
    int start = 0;

    for (int end = 0; end < n; ++end)
    {
        sum += cost[end];
        while (sum > maxCost)
        {
            sum -= cost[start];
            start++;
        }
        ans = max(ans, end - start + 1);
    }

    cout << ans;
    return 0;
}
