#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<string> words = {"cat", "dog", "tac", "god", "act"};
    unordered_map<string, vector<string>> anagrams;
    for (int i = 0; i < words.size(); i++)
    {
        int arr[26] = {0};
        for (int j = 0; j < words[i].size(); j++)
        {
            arr[words[i][j] - 'a']++;
        }
        string s = "";
        for (int j = 0; j < 26; j++)
        {
            s += to_string(arr[j]) + char(j + 'a');
        }
        anagrams[s].push_back(words[i]);
    }
    for (auto i : anagrams)
    {
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
