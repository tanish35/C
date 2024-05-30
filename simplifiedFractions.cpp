#include <bits/stdc++.h>
#include <algorithm>
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
    int n = 4;
    vector<string> result;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (__gcd(i, j) == 1)
            {
                result.push_back(to_string(i) + "/" + to_string(j));
            }
        }
    }
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}