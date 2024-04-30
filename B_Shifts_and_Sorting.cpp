#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
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
        ll res = 0;
        ll flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '1' && flag > 0)
            {
                int temp = flag + 1;
                res += temp;
                temp = 0;
            }
            else if (s[i] == '1')
            {
                flag++;
            }
        }
        cout << res << endl;
    }
}
