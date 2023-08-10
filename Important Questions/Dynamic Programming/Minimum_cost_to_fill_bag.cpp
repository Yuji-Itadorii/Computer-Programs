// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.

class Solution
{

    long long int helper(int cost[], int n, int w, vector<vector<long long int>> &dp)
    {
        if (w == 0)
            return (0);
        if (n == 0 || w < 0)
            return (INT_MAX);

        if (dp[n][w] != -1)
            return (dp[n][w]);

        if (n <= w && cost[n - 1] != -1)
        {
            return dp[n][w] = min(cost[n - 1] + helper(cost, n, w - n, dp), helper(cost, n - 1, w, dp));
        }
        return dp[n][w] = helper(cost, n - 1, w, dp);
    }

public:
    int minimumCost(int cost[], int n, int w)
    {
        // Your code goes here
        vector<vector<long long int>> dp(n + 1, vector<long long int>(w + 1, -1));

        long long int res = helper(cost, n, w, dp);
        return res == INT_MAX ? -1 : (int)res;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
}
// } Driver Code Ends