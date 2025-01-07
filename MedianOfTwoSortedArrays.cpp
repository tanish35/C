#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    if (n > m)
    {
        swap(nums1, nums2);
        swap(n, m);
    }
    int l = 0, r = n;
    while (l <= r)
    {
        int i = l + (r - l) / 2;
        int j = (n + m + 1) / 2 - i;
        int max1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int min1 = (i == n) ? INT_MAX : nums1[i];
        int max2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int min2 = (j == m) ? INT_MAX : nums2[j];
        if (max1 <= min2 && max2 <= min1)
        {
            if ((n + m) % 2 == 0)
                return (max(max1, max2) + min(min1, min2)) / 2.0;
            else
                return max(max1, max2);
        }
        else if (max1 > min2)
            r = i - 1;
        else
            l = i + 1;
    }
}

int main()
{
    vi nums1 = {1, 3}, nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}