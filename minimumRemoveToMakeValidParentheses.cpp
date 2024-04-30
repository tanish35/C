#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s = "lee(t(c)o)de)";
    vector<int> open;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open.push_back(i);
        }
        else if (s[i] == ')')
        {
            if (open.size() > 0)
            {
                open.pop_back();
            }
            else
            {
                s[i] = '*';
            }
        }
    }
    for (int i = 0; i < open.size(); i++)
    {
        s[open[i]] = '*';
    }

    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            res += s[i];
        }
    }
    cout << res;
}