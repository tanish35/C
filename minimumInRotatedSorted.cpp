#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int min = nums[0];
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (min > nums[mid])
        {
            min = nums[mid];
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << min;
}