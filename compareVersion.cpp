#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

void splitAndPush(string &version, vector<int> &v)
{
    int i = 0, j = 0;

    while (j <= version.size())
    {
        if (j == version.size() || version[j] == '.')
        {
            v.push_back(stoi(version.substr(i, j - i)));
            i = j + 1;
        }
        j++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string version1 = "1.01";
    string version2 = "1.001";
    vector<int> v1;
    vector<int> v2;
    splitAndPush(version1, v1);
    // splitAndPush(version2, v2);

    for (auto i : v1)
    {
        cout << i;
    }
}