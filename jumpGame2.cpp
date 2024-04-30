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
    vi nums = {2, 3, 1, 1, 4};
    int res = 0;
    int l = 0, r = 0;
    while (r < nums.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        res++;
    }
    cout << res;
    return 0;
}