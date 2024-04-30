#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 3;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i + 1 - mp[nums[i]] <= k && mp[nums[i]] != 0)
        {
            cout << "true";
            return 0;
        }
        mp[nums[i]] = i + 1;
    }
    cout << "false";
}