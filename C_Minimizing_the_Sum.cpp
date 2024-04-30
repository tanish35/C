#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define umap unordered_map<ll, ll>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vi nums;
        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            nums.push_back(temp);
        }

        vvi dp(n, vi(k + 1));
        ll temp = n - 1;

        for (ll i = 0; i <= k; i++)
        {
            dp[temp][i] = nums[temp];
        }
        temp--;
        for (ll i = temp; i >= 0; i--)
        {
            for (ll j = 0; j <= k; j++)
            {
                ll minVal = nums[i];
                ll count = 0;
                dp[i][j] = nums[i] + dp[i + 1][j];

                umap freq;

                long long l = i;
                while (l <= i + j)
                {
                    {
                        if (l <= n - 1)
                        {
                            if (nums[l] < minVal)
                            {
                                minVal = nums[l];
                                count = 1;
                            }
                            else if (nums[l] == minVal)
                            {
                                count++;
                            }

                            long total = l - i + 1;

                            if (l + 1 <= n - 1)
                            {
                                dp[i][j] = min(dp[i][j], minVal * total + dp[l + 1][j - (total - count)]);
                            }
                            else
                            {
                                dp[i][j] = min(dp[i][j], minVal * total);
                            }
                        }
                    }
                    l++;
                }
            }
        }

        cout << dp[0][k] << endl;
    }
}
