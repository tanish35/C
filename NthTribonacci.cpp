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
    int n = 25;
    int arr[3] = {0, 1, 1};
    for (int i = 3; i <= n; i++)
    {
        int temp = arr[0] + arr[1] + arr[2];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
    }
    cout << arr[2];
    return 0;
}