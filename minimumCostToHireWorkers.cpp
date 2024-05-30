#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi quality = {1, 2}, wage = {14, 16};
    int k = 1;
    int n = quality.size();
    vector<vector<double>> workers;
    for (int i = 0; i < n; i++)
    {
        workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
    }
    sort(workers.begin(), workers.end());
    double ans = DBL_MAX;
    double sum = 0;
    priority_queue<int> pq;
    for (auto worker : workers)
    {
        sum += worker[1];
        pq.push(worker[1]);
        if (pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k)
        {
            ans = min(ans, sum * worker[0]);
        }
    }
    cout << ans;
    return 0;
}