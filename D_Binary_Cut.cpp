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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cuts = 1;
        int flag = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
            {
                if (flag == 0)
                    flag = 1;
            }
            if (s[i] != s[i + 1])
                cuts++;
        }

        cout << cuts - flag << endl;
    }
    return 0;
}