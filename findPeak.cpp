#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int n = nums.size();
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << s << endl;
    return 0;
}