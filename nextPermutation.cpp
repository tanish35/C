#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi v = {1, 3, 2};
    int asc = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] < v[i + 1])
        {
            asc = i + 1;
        }
    }
    if (asc == 0)
    {
        reverse(v.begin(), v.end());
    }
    else
    {
        int j = v.size() - 1;
        while (v[j] <= v[asc - 1])
        {
            j--;
        }
        swap(v[j], v[asc - 1]);
        reverse(v.begin() + asc, v.end());
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}