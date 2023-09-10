// https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int ans = 1e9;
    void solve(vector<vector<int>> &grid, int idx, int cnt, int n, int m)
    {
        if (idx >= 9)
        {
            int flag = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grid[i][j] != 1)
                        flag = false;
                }
            }
            if (flag)
                ans = min(ans, cnt);
            return;
        }

        int x = idx / 3, y = idx % 3;
        if (grid[x][y] == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grid[i][j] > 1)
                    {
                        grid[i][j] -= 1;
                        grid[x][y] += 1;
                        solve(grid, idx + 1, cnt + abs(x - i) + abs(y - j), n, m);
                        grid[x][y] -= 1;
                        grid[i][j] += 1;
                    }
                }
            }
        }
        else
            solve(grid, idx + 1, cnt, n, m);
    }
    int minimumMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.size();
        solve(grid, 0, 0, n, m);
        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = s[j] - '0';
            }
        }
        cout << ob.minimumMoves(grid) << endl;
        }
    return 0;
}