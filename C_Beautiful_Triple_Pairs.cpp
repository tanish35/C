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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        map<tuple<int, int, int>, int> cnt;
        ll ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            tuple<int, int, int> triplet = {a[i], a[i + 1], a[i + 2]};
            vector<tuple<int, int, int>> dup(3);
            dup[0] = {0, a[i + 1], a[i + 2]};
            dup[1] = {a[i], 0, a[i + 2]};
            dup[2] = {a[i], a[i + 1], 0};
            int c = 0;
            for (const auto &trip : dup)
            {
                ans += cnt[trip] - cnt[triplet];
                cnt[trip]++;
            }
            cnt[triplet]++;

            ans += c;
        }
        cout << ans << endl;
    }
}
