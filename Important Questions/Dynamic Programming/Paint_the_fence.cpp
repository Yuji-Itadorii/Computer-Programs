// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
class Solution
{

private:
    long long mod = 1e9 + 7;

    long long solve(int n, int k, vector<long long> &dp)
    {

        if (n == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return k;
        }

        if (n == 2)
            return k * k;

        if (dp[n] != -1)
            return dp[n];

        int opt1 = 0, opt2 = 0;

        opt1 = solve(n - 1, k, dp) * (k - 1) % mod;
        opt2 = (solve(n - 2, k, dp) * (k - 1) % mod);

        return dp[n] = (opt1 + opt2) % mod;
    }

public:
    long long countWays(int n, int k)
    {
        // code here
        vector<long long> dp(n + 1, -1);
        return solve(n, k, dp);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends