#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_set<int> row;
    unordered_set<int> col;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row.find(i) != row.end() || col.find(j) != col.end())
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}