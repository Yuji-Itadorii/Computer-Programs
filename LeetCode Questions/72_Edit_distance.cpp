// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

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

    int minDistance(string t, string s)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, t, dp);
    }
};

int main()
{
    string str, t;
    cin >> str >> t;

    Solution s;
    cout << s.minDistance(t, str) << endl;

    return 0;
}