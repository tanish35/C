#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define umap unordered_map<int, int, custom_hash>
#define uset unordered_set<int, custom_hash>

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

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
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll sum = 0;
        ll lcm1 = a[0];
        for (int i = 1; i < n; i++)
        {
            lcm1 = lcm(lcm1, a[i]);
        }
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = lcm1 / a[i];
            sum += lcm1 / a[i];
        }
        if (sum >= lcm1)
        {
            cout << -1;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << b[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
