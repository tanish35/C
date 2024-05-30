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
    vector<int> score = {10, 3, 8, 9, 4};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> res;
    vector<int> temp = score;
    sort(temp.begin(), temp.end(), greater<int>());
    unordered_map<int, string> mp;
    mp[temp[0]] = "Gold Medal";
    mp[temp[1]] = "Silver Medal";
    mp[temp[2]] = "Bronze Medal";
    for (int i = 3; i < temp.size(); i++)
    {
        mp[temp[i]] = to_string(i + 1);
    }
    for (int i = 0; i < score.size(); i++)
    {
        res.push_back(mp[score[i]]);
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}