#include <iostream>
#include <vector>
using namespace std;
vector<int> rows(int s, int n, int i)
{
    vector<int> v;
    v.push_back(i);
    int h = (2 * n - (i + 1) * 2);
    int l = 2 * i;
    int m = i;
    for (int j = 0; m < s; j++)
    {
        if (j % 2 == 0 && h != 0)
        {
            m = m + h;
            if (m > s)
            {
                break;
            }
            v.push_back(m);
        }
        else if (j % 2 != 0 && l != 0)
        {
            m = m + l;
            if (m > s)
            {
                break;
            }
            v.push_back(m);
        }
    }
    return v;
}
int main()
{
    // string s = "PAYPALISHIRING";
    // int n = 4;
    // int l = s.length();
    // string p = "";
    // vector<int> v;
    // for (int i = 0; i < n; i++)
    // {
    //     v = rows(l, n, i);
    //     for (int j = 0; j < v.size(); j++)
    //     {
    //         p = p + s[v[j]];
    //     }
    // }
    // cout << p;

    vector<int> v = rows(13, 4, 2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}