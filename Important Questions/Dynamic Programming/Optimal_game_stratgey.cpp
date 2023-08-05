// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    long long solve(int i, int j, int n, int arr[], vector<vector<int>> &dp)
    {

        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        long long opt1 = arr[i] + min(solve(i + 1, j - 1, n, arr, dp), solve(i + 2, j, n, arr, dp));
        long long opt2 = arr[j] + min(solve(i + 1, j - 1, n, arr, dp), solve(i, j - 2, n, arr, dp));

        return dp[i][j] = max(opt1, opt2);
    }

    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, n, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends