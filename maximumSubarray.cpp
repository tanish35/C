#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxSum;
}