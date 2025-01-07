#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < n; i++)
#define sorta(arr) sort(arr.begin(), arr.end())
using namespace std;

ll totalCows(vll &arr, ll distance)
{
    ll cows = 1;
    ll currPos = arr[0];
    forn(i, arr.size())
    {
        if (arr[i] - currPos >= distance)
        {
            cows++;
            currPos = arr[i];
        }
    }
    return cows;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vll arr(n);
        forn(i, n)
        {
            cin >> arr[i];
        }
        sorta(arr);
        ll low = arr[1] - arr[0], high = arr[n - 1] - arr[0];
        ll ans = -1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (totalCows(arr, mid) >= c)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}