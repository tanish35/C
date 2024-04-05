#include <iostream>
#include <vector>
using namespace std;
vector<string> s;
string cur;
void backtrack(int open, int close, int n)
{
    if (open == n && close == n)
    {
        s.push_back(cur);
        return;
    }
    if (open < n)
    {
        cur += "(";
        backtrack(open + 1, close, n);
        cur.pop_back();
    }
    if (close < open)
    {
        cur += ")";
        backtrack(open, close + 1, n);
        cur.pop_back();
    }
}

int main()
{
    int n = 3;
    backtrack(0, 0, n);
    for (auto x : s)
    {
        cout << x << endl;
    }
}