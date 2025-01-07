#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

// Binary Search
int findDuplicateBinary(vector<int> &nums)
{
    ll n = nums.size();
    ll l = 1, r = n - 1;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
                count++;
        }
        if (count > mid)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

// Floyd's Tortoise and Hare (Cycle Detection)
int findDuplicateFloyd(vector<int> &nums)
{
    ll slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vi nums = {1, 3, 4, 2, 2};
    clock_t start, end;
    start = clock();
    cout << findDuplicateFloyd(nums) << endl;
    end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    cout << findDuplicateBinary(nums) << endl;
    end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}