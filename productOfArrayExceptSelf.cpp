#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi nums = {1, 2, 3, 4};
    int n = nums.size();
    vector<int> prefix(n + 1, 1);
    for (int i = 0; i < nums.size(); i++)
    {
        prefix[i + 1] = prefix[i] * nums[i];
    }
    vector<int> suffix(n + 1, 1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i];
    }
    int res[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = prefix[i] * suffix[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}