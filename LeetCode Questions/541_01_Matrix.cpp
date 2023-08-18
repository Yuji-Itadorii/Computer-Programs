// https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int l = 0;

        while (!q.empty())
        {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[r][c] = steps;

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                    vis[nr][nc] == 1)
                {
                    continue;
                }

                vis[nr][nc] = 1;
                q.push({{nr, nc}, steps + 1});
            }
        }

        return dis;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
        vector<vector<int>> ans = ob.updateMatrix(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
    return 0;
}