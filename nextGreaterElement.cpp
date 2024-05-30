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
    vi nums1 = {4, 1, 2};
    vi nums2 = {1, 3, 4, 2};
    vi ans;
    umap mp;
    stack<int> st;
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st.empty() && st.top() < nums2[i])
        {
            mp[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (mp[nums1[i]])
            ans.push_back(mp[nums1[i]]);
        else
            ans.push_back(-1);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}