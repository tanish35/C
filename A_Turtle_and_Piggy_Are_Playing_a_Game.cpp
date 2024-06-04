#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
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
        db a, b;
        cin >> a >> b;
        db base = log2(b);
        cout << (ll)base << endl;
    }
    return 0;
}