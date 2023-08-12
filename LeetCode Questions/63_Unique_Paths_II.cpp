// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

    bool safe(int i, int j, vector<vector<int>> &arr)
    {
        if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] == 1)
        {
            return false;
        }
        return true;
    }

    int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        int m = arr.size();
        int n = arr[0].size();
        if (i == m - 1 and j == n - 1)
        {
            return 1;
        }

        if (safe(i, j, arr) == false)
        {
            return dp[i][j] = 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // arr[i][j]= 1;
        dp[i][j] = solve(i, j + 1, arr, dp) + solve(i + 1, j, arr, dp);
        // arr[i][j] = 0;

        return dp[i][j];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m, 0));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePathsWithObstacles(arr) << endl;
    }
    return 0;
}