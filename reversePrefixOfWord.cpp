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
    string word = "abcefd";
    char ch = 'd';
    int i = 0;
    while (word[i] != ch && i < word.size())
        i++;
    if (i == word.size())
    {
        cout << word;
        return 0;
    }
    else
    {
        reverse(word.begin(), word.begin() + i + 1);
    }
    cout << word << endl;
    return 0;
}