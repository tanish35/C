#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {0, 1, 1, 0, 1};
    int c = 0;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] == 0)
        {
            c++;
            for (int j = i; j < n; j++)
            {
                nums[j] = nums[j] ^ 1;
            }
        }
        i++;
    }
    cout << c << endl;
    return 0;
}