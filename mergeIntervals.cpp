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
    int arr[1000] = {0};
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {5, 6}};
    // vector<vector<int>> intervals = {{1, 4}, {1, 4}};
    // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> result = {intervals[0]};
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        if (result.back()[1] >= intervals[i][0])
        {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }

    return 0;
}