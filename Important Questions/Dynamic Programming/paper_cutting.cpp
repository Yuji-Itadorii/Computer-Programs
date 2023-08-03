// https://practice.geeksforgeeks.org/problems/min-cut-square3303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int m, int n, vector<vector<int>> &dp)
    {
        if (m <= 0 || n <= 0)
        {
            return INT_MAX;
        }

        if (m == n)
        {
            return 1;
        }

        if (dp[m][n] != INT_MAX)
            return dp[m][n];

        for (int i = 1; i < m; i++)
            dp[m][n] = min(dp[m][n], solve(i, n, dp) + solve(m - i, n, dp));

        for (int i = 1; i < n; i++)

            dp[m][n] = min(dp[m][n], solve(m, i, dp) + solve(m, n - i, dp));

        return dp[m][n];
    }

    int minCut(int M, int N)
    {
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));

        return solve(M, N, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        Solution ob;
        cout << ob.minCut(m, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends