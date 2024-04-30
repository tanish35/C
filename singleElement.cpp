#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1};
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid == 0)
        {
            cout << nums[mid];
            break;
        }
        else if (mid == nums.size() - 1)
        {
            cout << nums[mid];
            break;
        }
        else
        {
            if (nums[mid + 1] != nums[mid] && nums[mid - 1] != nums[mid])
            {
                cout << nums[mid];
                break;
            }
            else if (nums[mid - 1] == nums[mid])
            {
                if ((mid - 1 - s) % 2 == 1)
                {
                    e = mid - 2;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if (nums[mid + 1] == nums[mid])
            {
                if ((mid - s) % 2 == 1)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 2;
                }
            }
        }
    }
    return 0;
}