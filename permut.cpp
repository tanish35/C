#include <vector>
#include <iostream>
#include <algorithm>
#include <string> // Include <string> header for std::stoi
using namespace std;

vector<int> v = {0, 1};
vector<vector<int>> p;

vector<int> permut(vector<int> cur, int j)
{
    if (j == 5)
    {
        p.push_back(cur);
        return cur;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cur.push_back(v[i]);
        permut(cur, j + 1);
        cur.pop_back();
    }
    return cur;
}

int main()
{
    vector<int> cur;
    int j = 0;
    permut(cur, j);
    for (int i = 0; i < p.size(); i++)
    {
        int number = 0;
        for (int j = 0; j < p[i].size(); j++)
        {
            number = number * 10 + p[i][j];
        }
        cout << number << endl;
    }
    return 0;
}
