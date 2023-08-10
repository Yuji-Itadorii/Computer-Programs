// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int solve(int n, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (n == 0 || w == 0)
        {
            return 0;
        }

        if (dp[n][w] != -1)
        {
            return dp[n][w];
        }

        if (w < wt[n - 1])
        {
            dp[n][w] = solve(n - 1, w, val, wt, dp);
        }
        else
        {
            dp[n][w] = max(solve(n - 1, w, val, wt, dp), val[n - 1] + solve(n, w - wt[n - 1], val, wt, dp));
        }

        return dp[n][w];
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here

        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

        return solve(N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends