#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a, b;
vector<vector<int>> dp;

// Function to solve the problem using recursion + DP
int solve(int pos, vector<int> &c)
{
    if (pos == n)
    {
        // Count small indices when C is fully constructed
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = j + 1; k < i; k++)
                {
                    if (c[i] <= c[j] + c[k])
                    {
                        count++;
                        break; // One valid pair is enough
                    }
                }
            }
        }
        return count;
    }

    // Use DP to avoid recomputation
    if (dp[pos][c[pos]] != -1)
    {
        return dp[pos][c[pos]];
    }

    // Option 1: Choose A[pos]
    c[pos] = a[pos];
    int chooseA = solve(pos + 1, c);

    // Option 2: Choose B[pos]
    c[pos] = b[pos];
    int chooseB = solve(pos + 1, c);

    // Store the result in DP
    return dp[pos][c[pos]] = max(chooseA, chooseB);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        a.resize(n);
        b.resize(n);
        dp.assign(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> c(n, 0); // Resultant array
        cout << solve(0, c) << '\n';
    }

    return 0;
}
