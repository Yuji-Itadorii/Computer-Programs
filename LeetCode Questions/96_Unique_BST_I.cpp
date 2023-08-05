// https://leetcode.com/problems/unique-binary-search-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int buildTree(int n, vector<int> &dp)
    {

        if (n <= 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += buildTree(i - 1, dp) * buildTree(n - i, dp);
        }

        return dp[n] = ans;
    }

public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return buildTree(n, dp);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.numTrees(n) << endl;
    }

    return 0;
}