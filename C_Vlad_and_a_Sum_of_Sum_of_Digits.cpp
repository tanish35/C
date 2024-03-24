#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long k;
        long long sum = 0;
        cin >> k;
        for (long long j = 1; j <= k; j++)
        {
            long long b = j;
            while (b != 0)
            {
                sum += b % 10;
                b /= 10;
            }
        }
        cout << sum << endl;
    }
}