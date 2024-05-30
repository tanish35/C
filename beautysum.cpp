#include <bits/stdc++.h>
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
    string s = "aabcbaa";
    int n = s.size();
    int beautySum = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++)
        {
            freq[s[j]]++;
            int maxFreq = 0;
            for (auto it = freq.begin(); it != freq.end(); it++)
            {
                if (it->second > maxFreq)
                {
                    maxFreq = it->second;
                }
            }
            int minFreq = INT_MAX;
            for (auto it = freq.begin(); it != freq.end(); it++)
            {
                if (it->second < minFreq)
                {
                    minFreq = it->second;
                }
            }
            beautySum += maxFreq - minFreq;
        }
    }
    cout << beautySum << endl;
}