#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[(nums[i]) / std::abs(nums[i])].push_back(nums[i]);
    }
    vector<int> res;
    int n = nums.size() / 2;
    int i = 0;
    while (i < n)
    {
        res.push_back(m[1][i]);
        res.push_back(m[-1][i]);
        i++;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}