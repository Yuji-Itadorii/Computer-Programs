// https://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    bool DFS(vector<vector<char>> &board, string word, int i, int j, int n)
    {
        if (n == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n])
            return false;

        board[i][j] = '0';

        bool status = DFS(board, word, i + 1, j, n + 1) || // down
                      DFS(board, word, i, j + 1, n + 1) || // right
                      DFS(board, word, i - 1, j, n + 1) || // up
                      DFS(board, word, i, j - 1, n + 1);   // left

        board[i][j] = word[n];

        return status;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word == "")
            return false;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;

        return false;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        }
        string word;
        cin >> word;
        cout << ob.exist(board, word) << endl;
    }
    return 0;
}