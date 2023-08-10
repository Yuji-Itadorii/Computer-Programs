// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below method */

    long long fun(int i, int j, string &str, vector<vector<long long int>> &dp)
    {
        int mod = 1e9 + 7;
        if (i == j)
        {
            return 1;
        }

        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (str[i] == str[j])
        {
            dp[i][j] = (1 + fun(i + 1, j, str, dp) + fun(i, j - 1, str, dp)) % mod;
        }
        else
        {
            dp[i][j] = ((fun(i + 1, j, str, dp) + fun(i, j - 1, str, dp) - fun(i + 1, j - 1, str, dp)) % mod + mod) % mod;
        }

        return dp[i][j];
    }

    long long int countPS(string str)
    {
        // Your code here
        int n = str.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return fun(0, n - 1, str, dp);
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends