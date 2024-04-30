#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string num = "9";
    int k = 1;
    stack<char> s;
    for (int i = 0; i < num.size(); i++)
    {
        while (!s.empty() && k > 0 && s.top() > num[i])
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    while (k > 0)
    {
        s.pop();
        k--;
    }
    string res = "";
    while (!s.empty())
    {
        res = s.top() + res;
        s.pop();
    }
    int flag = 0;
    if (res[0] == '0')
    {
        flag = 1;
    }
    while (flag != 0)
    {
        res.erase(0, 1);
        if (res[0] != '0')
        {
            flag = 0;
        }
    }
    cout << res;
}