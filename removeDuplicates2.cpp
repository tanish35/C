#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> nums = {1, 1, 2, 2, 2, 2, 3, 3};
    vector<int> nums = {1, 1, 2, 3, 4};
    int c = 1;
    int j = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[j] && c < 2)
        {
            j++;
            nums[j] = nums[i];
            c++;
        }
        else if (nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
            c = 1;
        }
    }
    for (int i = 0; i < j + 1; i++)
    {
        cout << nums[i] << " ";
    }
}