#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
void backtrack(int row, int n, vector<string> &board, vector<int> &cols,
               vector<int> &negdia, vector<int> &posdia,
               vector<vector<string>> &res)
{
    if (row == n)
    {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (!cols[col] && !negdia[row - col + n - 1] &&
            !posdia[row + col])
        {
            cols[col] = negdia[row - col + n - 1] = posdia[row + col] = 1;
            board[row][col] = 'Q';
            backtrack(row + 1, n, board, cols, negdia, posdia, res);
            cols[col] = negdia[row - col + n - 1] = posdia[row + col] = 0;
            board[row][col] = '.';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 4;
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    vector<int> cols(n), negdia(2 * n - 1), posdia(2 * n - 1);

    backtrack(0, n, board, cols, negdia, posdia, res);
    cout << res.size() << endl;
    // for (auto &x : res)
    // {
    //     for (auto &y : x)
    //     {
    //         cout << y << endl;
    //     }
    //     cout << endl;
    // }
}
