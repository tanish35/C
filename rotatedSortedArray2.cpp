#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    int target = 3;
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target || nums[s] == target || nums[e] == target)
        {
            cout << "true";
            return 0;
        }

        if (nums[s] < nums[mid])
        {
            if (target >= nums[s] && target <= nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (nums[s] == nums[mid])
        {
            s++;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    cout << "false";
}