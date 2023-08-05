// https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<char>> &arr, int i, int j, int m, int n, vector<vector<int>> &vis)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or arr[i][j] == '0' || vis[i][j] == 1)
            return;

        vis[i][j] = 1;

        DFS(arr, i - 1, j, m, n, vis);
        DFS(arr, i + 1, j, m, n, vis);
        DFS(arr, i, j - 1, m, n, vis);
        DFS(arr, i, j + 1, m, n, vis);
    }

    int numIslands(vector<vector<char>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '1')
                {
                    if (vis[i][j] == 0)
                    {
                        count++;
                        DFS(arr, i, j, m, n, vis);
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> arr = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};

    cout << obj.numIslands(arr);

        return 0;
}