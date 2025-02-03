#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < n; i++)
#define sorta(v) sort(v.begin(), v.end())
using namespace std;

int smallestDistancePair(vector<int> &nums, int k)
{
    ll n = nums.size();
    sorta(nums);
    ll l = 0, r = nums[n - 1] - nums[0];
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            while (j < n && nums[j] - nums[i] <= mid)
                j++;
            cnt += j - i - 1;
        }
        if (cnt >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 6, 1};
    int k = 3;
    cout << smallestDistancePair(nums, k) << endl;

    return 0;
}