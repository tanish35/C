#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};
    sort(piles.rbegin(), piles.rend());
    int h = 6;
    int n = piles.size();
    int k = h - n;
    int arr[n];
    std::fill(arr, arr + n, 1);
    int s[2] = {0};
    s[0] = piles[0];
    while (k > 0)
    {
        arr[0]++;
        cout << piles[0] << " " << arr[0] << endl;
        s[1] = ceil((float)piles[0] / arr[0]);
        int temph = 1;
        cout << s[1] << endl;
        for (int i = 1; i < n && s[1] < piles[i]; i++)
        {
            cout << "piles[i]: " << piles[i] << endl;
            cout << "arr[i]: " << arr[i] << endl;
            if (ceil((float)piles[i] / arr[i]) > s[1])
            {
                arr[i]++;
                temph++;
            }
        }
        cout << "k: " << k << endl;
        cout << "temph: " << temph << endl;
        if (temph <= k)
        {
            s[0] = s[1];
            k -= temph;
        }
        else
        {
            break;
        }
    }
    // cout << s[0] << endl;
}