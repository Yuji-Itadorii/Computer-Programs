// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?page=1&difficulty[]=1&difficulty[]=2&status[]=unsolved&company[]=Microsoft&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dp[1001][1001];

    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int n, int w, int wt[], int val[])
    {

        if (n == 0 || w == 0)
        {
            return 0;
        }

        if (dp[n][w] != -1)
        {
            return dp[n][w];
        }

        if (wt[n - 1] <= w)
        {
            return dp[n][w] = max(solve(n - 1, w, wt, val), val[n - 1] + solve(n - 1, w - wt[n - 1], wt, val));
        }
        else
        {
            return dp[n][w] = solve(n - 1, w, wt, val);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        return solve(n, W, wt, val);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends