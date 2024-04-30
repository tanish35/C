#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>

vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
int m = board.size();
int n = board[0].size();
int getNeighbours(int i, int j)
{
    int count = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int new_i = i + dx;
            int new_j = j + dy;
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !(dx == 0 && dy == 0) && (board[new_i][new_j] == 1 || board[new_i][new_j] == 3))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = getNeighbours(i, j);
            if (board[i][j] == 1)
            {
                if (count < 2 || count > 3)
                {
                    board[i][j] = 3;
                }
            }
            else
            {
                if (count == 3)
                {
                    board[i][j] = 2;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 2)
            {
                board[i][j] = 1;
            }
            else if (board[i][j] == 3)
            {
                board[i][j] = 0;
            }
        }
    }

    return 0;
}
