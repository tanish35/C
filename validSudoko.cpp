#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    unordered_map<string, int> row;
    unordered_map<string, int> col;
    unordered_map<string, int> box;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                string rowKey = board[i][j] + to_string(i);
                string colKey = board[i][j] + to_string(j);
                string boxKey = board[i][j] + to_string(i / 3) + to_string(j / 3);
                if (row[rowKey] > 0 || col[colKey] > 0 || box[boxKey] > 0)
                {
                    cout << "false";
                    return 0;
                }
                else
                {
                    row[rowKey]++;
                    col[colKey]++;
                    box[boxKey]++;
                }
            }
        }
    }
    cout << "true";
}