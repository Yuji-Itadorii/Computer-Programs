// https://practice.geeksforgeeks.org/problems/bbt-counter4914/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

    long long int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (solve(n - 1, dp) * solve(n - 1, dp) + 2 * solve(n - 2, dp) * solve(n - 1, dp)) % 1000000007;
    }

public:
    long long int countBT(int h)
    {
        // code here
        vector<int> dp(h + 1, -1);
        return solve(h, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h;
        cin >> h;
        Solution ob;
        cout << ob.countBT(h) << endl;
    }
    return 0;
}

// } Driver Code Ends