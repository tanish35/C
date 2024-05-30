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
    vector<int> nums = {0, 0};
    int arr[1001] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= nums[i]; j++)
        {
            arr[j]++;
        }
    }
    for (int i = 0; i < 101; i++)
    {
        if (arr[i] == i)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}