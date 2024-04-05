#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int *l = &v[0];
    int *r = &v[v.size() - 1];
    int n = 0;
    int maxLeft = *l;
    int maxRight = *r;
    while (l <= r)
    {
        maxLeft = max(maxLeft, *l);
        maxRight = max(maxRight, *r);
        if (maxLeft < maxRight)
        {
            n += maxLeft - *l;
            l++;
        }
        else
        {
            n += maxRight - *r;
            r--;
        }
    }
    cout << n;
}