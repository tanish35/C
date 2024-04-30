// #include <iostream>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         long long k;
//         cin >> n >> k;
//         long long a[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         int sunk = 0;
//         long long *s = &a[0];
//         long long *e = &a[n - 1];
//         while (k >= 0 && s < e)
//         {
//             if (*s + *e <= k)
//             {
//                 if (*s > *e)
//                 {
//                     k -= (*e) * 2;
//                     *s = *s - *e;
//                     sunk++;
//                     e--;
//                 }
//                 else if (*s < *e)
//                 {
//                     k -= (*s) * 2;
//                     *e = *e - *s;
//                     sunk++;
//                     s++;
//                 }
//                 else
//                 {
//                     k -= (*s + *e);
//                     s++;
//                     sunk += 2;
//                     e--;
//                 }
//             }
//             else
//             {
//                 break;
//             }
//         }
//         if (s != e && k > 0)
//         {
//             while (k >= 0)
//             {
//                 *s = *s - 1;
//                 k--;
//                 if (*s == 0 && k >= 0)
//                 {
//                     sunk++;
//                     break;
//                 }
//                 *e = *e - 1;
//                 k--;
//                 if (*s == 0 && k >= 0)
//                 {
//                     sunk++;
//                     break;
//                 }
//             }
//         }
//         if (s == e && k > 0)
//         {
//             if (k >= *s)
//                 sunk++;
//         }
//         cout << sunk << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (k >= s)
        {
            cout << n << endl;
            continue;
        }
        int i = 0, j = n - 1, ans = 0;
        while (k && (i < j))
        {
            if (k >= (2 * min(a[i], a[j])))
            {
                ans++;
                k -= (2 * min(a[i], a[j]));
                if (a[i] < a[j])
                {
                    a[j] -= a[i];
                    i++;
                }
                else if (a[i] == a[j])
                {
                    i++;
                    j--;
                    ans++;
                }
                else
                {
                    a[i] -= a[j];
                    j--;
                }
            }
            else if ((k + 1) == (2 * min(a[i], a[j])) && a[i] <= a[j])
            {
                ans++;
                break;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}