// https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool solve(string &str, string &pattern, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 && j < 0)
        {
            return true;
        }

        if (i >= 0 && j < 0)
        {
            return false;
        }

        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (pattern[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (str[i] == pattern[j] || pattern[j] == '?')
        {
            return dp[i][j] = solve(str, pattern, i - 1, j - 1, dp);
        }
        else if (pattern[j] == '*')
        {
            return dp[i][j] = (solve(str, pattern, i - 1, j, dp) || solve(str, pattern, i, j - 1, dp));
        }
        else
        {
            return false;
        }
    }

    bool match(string wild, string pattern)
    {
        // code here
        string str = pattern;
        string patt = wild;
        vector<vector<int>> dp(str.length(), vector<int>(patt.length(), -1));
        return solve(str, wild, str.size() - 1, patt.size() - 1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
// } Driver Code Ends