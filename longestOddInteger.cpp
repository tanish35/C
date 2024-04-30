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
    string num = "35427";
    int pt = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            pt = i;
        }
    }

    cout << num.substr(0, pt + 1) << endl;
    return 0;
}