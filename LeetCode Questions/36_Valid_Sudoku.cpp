// https://leetcode.com/problems/valid-sudoku/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

    bool isValid(int r, int c, int val, vector<vector<char>> &grid)
    {
        grid[r][c] = '.';
        for (int k = 0; k < 9; k++)
        {
            if (grid[r][k] == val || grid[k][c] == val)
            {
                return false;
            }
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[r / 3 * 3 + i][c / 3 * 3 + j] == val)
                    return false;

        grid[r][c] = val;

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (isValid(i, j, board[i][j], board) == false)
                    {
                        // cout<<board[i][j]<<endl;
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        vector<vector<char>> board(9, vector<char>(9));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> board[i][j];
            }
        }
        cout << ob.isValidSudoku(board) << endl;
    }
    return 0;
}