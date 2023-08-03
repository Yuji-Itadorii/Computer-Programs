// https://practice.geeksforgeeks.org/problems/edit-distance3702/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int n, int m, string &s, string &t, vector<vector<int>> &dp)
    {

        if (n == 0 && m == 0)
        {
            return 0;
        }

        if (m == 0)
            return dp[n][m] = n;
        if (n == 0)
            return dp[n][m] = m;

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }

        if (s[n - 1] == t[m - 1])
        {
            dp[n][m] = solve(n - 1, m - 1, s, t, dp);
        }
        else
        {
            dp[n][m] = 1 + min({solve(n, m - 1, s, t, dp),
                                solve(n - 1, m, s, t, dp),
                                solve(n - 1, m - 1, s, t, dp)});
        }

        return dp[n][m];
    }

    int editDistance(string s, string t)
    {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, t, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends