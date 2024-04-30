#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<char, char>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string message = "vkbs bs t suepuv";
    string key = "the quick brown fox jumps over the lazy dog";

    umap mp;

    int j = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] != ' ' && mp.find(key[i]) == mp.end())
        {
            mp[key[i]] = 'a' + j;
            j++;
        }
    }

    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] != ' ')
        {
            cout << mp[message[i]];
        }
        else
        {
            cout << ' ';
        }
    }
    return 0;
}