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
    vi nums = {-1, 10, 6, 7, -7, 1};
    int m = 0;
    umap mp;
    for (auto &i : nums)
    {
        if (mp[i])
        {
            if (m < abs(i))
            {
                m = abs(i);
            }
        }
        else
        {
            mp[-1 * i] = 1;
        }
    }
    cout << m;
    return 0;
}