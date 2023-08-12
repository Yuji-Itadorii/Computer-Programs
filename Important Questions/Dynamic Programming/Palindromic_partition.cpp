// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    bool check(string &s, int row, int col)
    {
        while (row < col)
        {
            if (s[row++] != s[col--])
                return false;
        }
        return true;
    }

public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        int dp[n][n];

        for (int gap = 0; gap < n; gap++)
        {
            for (int row = 0, col = gap; col < n; row++, col++)
            {
                if (gap == 0)
                {
                    dp[row][col] = 0;
                }
                else if (check(str, row, col))
                {
                    dp[row][col] = 0;
                }
                else
                {
                    dp[row][col] = INT_MAX;
                    for (int k = row; k < col; k++)
                    {
                        dp[row][col] = min(dp[row][col], 1 + dp[row][k] + dp[k + 1][col]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends