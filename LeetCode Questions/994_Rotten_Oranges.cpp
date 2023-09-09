// https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int x[] = {1, 0, -1, 0};
        int y[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int count = -1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto itr = q.front();
                q.pop();

                int r = itr.first;
                int c = itr.second;

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + x[i];
                    int nc = c + y[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0 || grid[nr][nc] == 2)
                    {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
            count++;
        }

        if (fresh > 0)
            return -1;
        if (count == -1)
            return 0;
        return count;
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
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> grid[i / m][i % m];

        cout << ob.orangesRotting(grid) << "\n";
    }
    return 0;
}