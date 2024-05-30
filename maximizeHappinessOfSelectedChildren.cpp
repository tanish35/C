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
    vi happiness = {1, 3, 2};
    int k = 2;
    sort(happiness.begin(), happiness.end(), greater<int>());
    int res = 0;
    int c = 0;
    for (int i = 0; i < k; i++)
    {
        if (happiness[i] - c >= 0)
        {
            res += happiness[i] - c;
            c++;
        }
        else
        {
            break;
        }
    }
    cout << res << endl;
    return 0;
}