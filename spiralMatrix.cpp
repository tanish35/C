#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
    vi res;
    while (left < right && top < bottom)
    {
        for (int i = left; i < right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i < bottom; i++)
        {
            res.push_back(matrix[i][right - 1]);
        }
        right--;
        if (top < bottom)
        {
            for (int i = right - 1; i >= left; i--)
            {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
        }
        if (left < right)
        {
            for (int i = bottom - 1; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return 0;
}