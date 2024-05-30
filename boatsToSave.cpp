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
    vi people = {1, 1, 1, 1, 1, 1, 1, 1};
    int limit = 8;
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int boats = 0;
    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        boats++;
    }
    cout << boats << endl;
    return 0;
}