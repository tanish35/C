#include <bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define db double
#define vi vector<int>
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long n = bloomDay.size();
    if (n < (long long)m * (long long)k)
        return -1;
    long long l = *min_element(bloomDay.begin(), bloomDay.end()), r = *max_element(bloomDay.begin(), bloomDay.end());
    while (l < r)
    {
        long long mid = l + (r - l) / 2, flowers = 0, bouquets = 0;
        for (long long i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
                flowers++;
            else
                flowers = 0;
            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        if (bouquets < m)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main()
{

    return 0;
}