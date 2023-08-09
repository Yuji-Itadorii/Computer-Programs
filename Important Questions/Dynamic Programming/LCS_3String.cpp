// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int LCS(string &s1, string &s2, string &s3)
{
    int l = s1.size();
    int m = s2.size();
    int n = s3.size();

    vector<vector<vector<int>>> dp(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[0][i][j] = 0;
        }
    }

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][0][j] = 0;
        }
    }

    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }

    return dp[l][m][n];
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{

    return LCS(A, B, C);
}