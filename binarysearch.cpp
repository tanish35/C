#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        if (nums[(s + e) / 2] == target)
        {
            cout << (s + e) / 2;
            return 0;
        }
        else if (nums[(s + e) / 2] < target)
        {
            s = (s + e) / 2 + 1;
        }
        else
        {
            e = (s + e) / 2 - 1;
        }
    }
    cout << "Not found";
}