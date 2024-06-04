#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b(n);
        int g = 0;
        int p = -1;
        for (int i = 0; i < n - 1; i++)
        {
            b[i] = __gcd(a[i], a[i + 1]);
            if (g > b[i] && p == -1)
            {
                p = i - 1;
            }
            g = b[i];
        }

        if (p == -1)
        {
            cout << "YES" << endl;
            continue;
        }

        vi a1, a2, a3;
        for (int i = 0; i < n; ++i)
        {
            if (i != p + 1)
                a1.push_back(a[i]);
            if (i != p + 2)
                a2.push_back(a[i]);
            if (i != p)
                a3.push_back(a[i]);
        }

        vi b1(n), b2(n), b3(n);
        for (int i = 0; i < n - 2; ++i)
        {
            b1[i] = __gcd(a1[i], a1[i + 1]);
            b2[i] = __gcd(a2[i], a2[i + 1]);
            b3[i] = __gcd(a3[i], a3[i + 1]);
        }

        bool flag1 = true, flag2 = true, flag3 = true;
        for (int i = 0; i < n - 3; ++i)
        {
            if (b1[i] > b1[i + 1])
                flag1 = false;
            if (b2[i] > b2[i + 1])
                flag2 = false;
            if (b3[i] > b3[i + 1])
                flag3 = false;
        }

        if (!(flag1 || flag2 || flag3))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
