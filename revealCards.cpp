#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    sort(deck.begin(), deck.end());
    vector<int> ans(deck.size());
    vector<int> index(deck.size());
    for (int i = 0; i < deck.size(); i++)
    {
        index[i] = i;
    }
    for (int card : deck)
    {
        ans[index[0]] = card;
        index.erase(index.begin());
        if (!index.empty())
        {
            index.push_back(index[0]);
            index.erase(index.begin());
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}