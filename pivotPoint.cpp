#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int pivot = 0;
    int pivotValue = nums[0];
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] > nums[0])
        {
            pivot = mid;
            pivotValue = nums[mid];
            s = mid + 1;
        }
        else if (nums[mid] == nums[0])
        {
            pivot = mid;
            s++;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (nums[pivot + 1] >= pivotValue)
    {
        pivot++;
        pivotValue = nums[pivot];
    }
    cout << pivotValue << endl;
    return pivot;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findPivot(nums);
    return 0;
}