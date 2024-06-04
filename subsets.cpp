#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
vvi res;
vi temp;
set<vi> s;
void backtrack(int start, vi &nums)
{
    if (s.find(temp) == s.end())
    {
        sort(temp.begin(), temp.end());
        res.push_back(temp);
        s.insert(temp);
    }
    for (int i = start; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrack(i + 1, nums);
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi nums = {4, 4, 1, 4};
    sort(nums.begin(), nums.end());
    backtrack(0, nums);

    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}