#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> v = {"23:59", "00:00", "22:42", "01:50"};
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
}