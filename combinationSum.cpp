#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
vvi result;
vi candidates = {2, 3, 6, 7};
int target = 7;
void recur(int curr, vi &temp, int sum)
{
    if (sum == target)
    {
        result.push_back(temp);
        return;
    }
    if (sum > target)
    {
        return;
    }
    for (int i = curr; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        recur(i, temp, sum + candidates[i]);
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi temp = {};
    recur(0, temp, 0);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}