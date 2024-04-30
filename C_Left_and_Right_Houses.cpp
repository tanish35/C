#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m = 3;
        cin >> m;
        string s = "101";
        cin >> s;
        unordered_set<int> right;
        int count1 = 0;
        int count0 = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (count1 >= count0)
            {
                right.insert(j);
            }
            if (s[j] == '1')
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }
        count1 = 0;
        count0 = 0;
        vector<int> ans;
        ans.push_back(0);
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
            {
                count1++;
            }
            else
            {
                count0++;
            }
            if (count0 >= count1)
            {
                if (right.find(j) != right.end())
                {
                    ans.push_back(j + 1);
                }
            }
        }
        // for (int j = 0; j < ans.size(); j++)
        // {
        //     cout << ans[j] << " ";
        // }
        // cout << endl;
        int min = 999;
        int k = 6754;
        for (int j = 0; j < ans.size(); j++)
        {
            if (abs((m / 2.0) - ans[j]) < min)
            {
                min = (m / 2) - ans[j];
                k = ans[j];
            }
        }
        if (k == 6754)
        {
            if (right.empty())
            {
                cout << m << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << k << endl;
        }
    }
}