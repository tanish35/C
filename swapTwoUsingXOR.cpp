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
    int a = 5, b = 7;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;
    return 0;
}