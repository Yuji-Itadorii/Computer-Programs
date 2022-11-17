#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, int m, string s2, int n)
{
    int memo[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            memo[i][j] = -1;
        }
    }

    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        memo[m][n] = 1 + LCS(s1, m - 1, s2, n - 1);
    }
    else
    {
        memo[m][n] = max(LCS(s1, m - 1, s2, n), LCS(s1, m, s2, n - 1));
    }

    return memo[m][n];
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout<<LCS(s1 , 6  , s2 , 6);

    return 0;
}