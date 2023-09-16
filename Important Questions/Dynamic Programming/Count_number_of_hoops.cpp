// https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long mod = 1000000007;
    long long solve(int n, long long sum, vector<long long> &dp)
    {
        if (sum > n)
        {
            return 0;
        }

        if (dp[sum] != -1)
        {
            return dp[sum];
        }

        if (sum == n)
        {
            return 1;
        }

        return dp[sum] = (solve(n, sum + 1, dp) + solve(n, sum + 2, dp) + solve(n, sum + 3, dp)) % mod;
    }

public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {

        // your code here
        vector<long long> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}

// } Driver Code Ends