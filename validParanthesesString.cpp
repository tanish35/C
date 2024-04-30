#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s = "**(()";
    vector<int> open;
    vector<int> star;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open.push_back(i);
        }
        else if (s[i] == '*')
        {
            star.push_back(i);
        }
        else if (s[i] == ')')
        {
            if (open.size() > 0)
            {
                s[open.back()] = '^';
                s[i] = '^';
                open.pop_back();
            }
            else if (star.size() > 0)
            {
                s[star.back()] = '^';
                s[i] = '^';
                star.pop_back();
            }
            else
            {
                cout << "false";
                return 0;
            }
        }
    }
    open.clear();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open.push_back(i);
        }
        else if (s[i] == '*')
        {
            if (open.size() > 0)
            {
                open.pop_back();
            }
        }
    }
    if (open.size() == 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}