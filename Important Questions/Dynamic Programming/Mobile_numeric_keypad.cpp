// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    long long solve(int i, int j, int n, vector<vector<vector<long long>>> &dp)
    {

        if (i == 3 and j == 0 || i == 3 and j == 2)
        {
            return 0;
        }

        if (i < 0 || i >= 4 || j < 0 || j >= 3)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }

        if (dp[i][j][n] != -1)
        {
            return dp[i][j][n];
        }

        return dp[i][j][n] = solve(i, j, n - 1, dp) + solve(i - 1, j, n - 1, dp) +
                             solve(i, j - 1, n - 1, dp) + solve(i, j + 1, n - 1, dp) + solve(i + 1, j, n - 1, dp);
    }

public:
    long long getCount(int N)
    {
        // Your code goes here
        long long ans = 0;

        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(N + 1, -1)));

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 3 and j == 0 || i == 3 and j == 2)
                {
                    continue;
                }
                else
                {
                    ans += solve(i, j, N, dp);
                }
            }
        }

        return ans;
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends