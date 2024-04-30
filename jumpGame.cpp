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
    vi nums = {3, 2, 1, 0, 4};
    int f = nums.size() - 1;
    for (int i = f - 1; i >= 0; i--)
    {
        if (nums[i] + i >= f)
        {
            f = i;
        }
    }
    if (f == 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}