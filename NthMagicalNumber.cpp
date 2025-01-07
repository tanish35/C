#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

int nthMagicalNumber(int n, int a, int b)
{
    ll mod = 1e9 + 7;
    ll lcm = a * b / __gcd(a, b);
    ll low = min(a, b);
    ll high = min(mod, 1ll * n * min(a, b));
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (mid / a + mid / b - mid / lcm < n)
            low = mid + 1;
        else
            high = mid;
    }
    return low % mod;
}

int main()
{

    return 0;
}