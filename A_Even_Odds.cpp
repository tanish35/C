#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    k = k - 1;
    long long m = 0;
    long long ans;
    if (n % 2 == 0)
    {
        m = (n / 2) - 1;
    }
    else
    {
        m = n / 2;
    }
    if (k <= m)
    {

        cout << 2 * k + 1;
    }
    else
    {
        cout << 2 * (k - m);
    }
}