#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi nums = {100, 4, 200, 1, 3, 2};
    uset s;
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i] - 1) == s.end()) {
            int j = nums[i];
            while (s.find(j) != s.end()) {
                j++;
            }
            ans = max(ans, j - nums[i]);
        }
    }
    
    return 0;
}