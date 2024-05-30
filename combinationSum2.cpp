#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
vvi result;
vi candidates = {10, 1, 2, 7, 6, 1, 5};
int target = 8;
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
        if (i > curr && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        recur(i + 1, temp, sum + candidates[i]);
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi temp = {};
    sort(candidates.begin(), candidates.end());
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