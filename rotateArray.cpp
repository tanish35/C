#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {-1};
    int k = 2;
    int n = nums.size();
    k = k % n;
    for (int i = 0; i < n - k; i++)
    {
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.begin() + n - k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}