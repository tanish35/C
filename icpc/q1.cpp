#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maxDiversity(ll N, ll K, vector<ll> &A)
{
    map<ll, ll> freq;
    ll sz = A.size();
    for (int i = 0; i < N; i++)
    {
        freq[A[i]]++;
    }

    ll sub = 0;
    ll ex = 0;
    ll rn = freq.size();
    for (auto i : freq)
    {
        if (i.second * rn > K)
            break;
        else
            ex = i.second;
    }
    ll ex2 = max(0ll, K - ex * rn);
    ll tans = 0;
    for (auto it = freq.rbegin(); it != freq.rend(); it++)
    {
        ll val = it->second - ex - (ex2 > 0);
        if (val > 0)
        {
            tans += val * (val - 1) / 2;
        }
        ex2--;
    }
    ll ans = sz * (sz - 1) / 2;
    return ans - tans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << maxDiversity(N, K, A) << endl;
    }
    return 0;
}
