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
    vi nums = {1, 2, 1};
    vi res(nums.size(), -1);
    stack<int> s;
    for (int i = 0; i < 2 * nums.size(); i++)
    {
        while (!s.empty() && nums[i % nums.size()] > nums[s.top()])
        {
            res[s.top()] = nums[i % nums.size()];
            s.pop();
        }
        if (i < nums.size())
            s.push(i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}