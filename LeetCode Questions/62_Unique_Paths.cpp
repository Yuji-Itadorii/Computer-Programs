// https://leetcode.com/problems/unique-paths/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    bool safe(int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        return true;
    }

    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i == m - 1 and j == n - 1)
        {
            return 1;
        }

        if (safe(i, j, m, n) == false)
        {
            return dp[i][j] = 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        dp[i][j] = solve(i, j + 1, m, n, dp) + solve(i + 1, j, m, n, dp);

        return dp[i][j];
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, m, n, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int m, n;
        cin >> m >> n;
        cout << s.uniquePaths(m, n) << endl;
    }
    return 0;
}