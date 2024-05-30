#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char> v = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int j = 0;
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[j] == v[i])
        {
            cout << v[j] << " " << v[i] << endl;
            c++;
        }
        else
        {
            j++;
            if (c > 1)
            {
                int x = 0;
                while (c != 0)
                {
                    x = x * 10 + c % 10;
                    c = c / 10;
                }
                while (x != 0)
                {
                    v[j] = x % 10 + '0';
                    x = x / 10;
                    j++;
                }
            }
            v[j] = v[i];
            c = 1;
        }
    }
    if (c > 1)
    {
        j++;
        int x = 0;
        while (c != 0)
        {
            x = x * 10 + c % 10;
            c = c / 10;
        }
        while (x != 0)
        {
            v[j] = x % 10 + '0';
            x = x / 10;
            j++;
        }
    }
    cout << j << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}