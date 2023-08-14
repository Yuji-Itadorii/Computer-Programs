// https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void DFS(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or board[i][j] != 'O')
            return;
        board[i][j] = '#';
        DFS(board, i - 1, j, m, n);
        DFS(board, i + 1, j, m, n);
        DFS(board, i, j - 1, m, n);
        DFS(board, i, j + 1, m, n);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        // Moving over firts and last column
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        // Moving over first and last row
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n);
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    obj.solve(board);

    for (auto i : board)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

        return 0;
}