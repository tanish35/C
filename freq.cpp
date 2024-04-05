#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {3, 9, 6};
    int k = 2;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        int l = k;
        int c = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] - nums[j] > l)
            {
                break;
            }
            else if (nums[i] - nums[j] <= l)
            {
                l = l - (nums[i] - nums[j]);
                c++;
            }
        }
        m = max(m, c);
    }
    cout << m;
}