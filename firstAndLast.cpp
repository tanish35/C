#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int s = 0;
    int e = nums.size() - 1;
    int first = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (target == nums[mid])
        {
            first = mid;
            e = mid - 1;
        }
        else if (target < nums[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    s = 0;
    e = nums.size() - 1;
    int last = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (target == nums[mid])
        {
            last = mid;
            s = mid + 1;
        }
        else if (target < nums[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout << first << " " << last;
}