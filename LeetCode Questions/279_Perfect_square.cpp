// https://leetcode.com/problems/perfect-squares/description//

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int solve(int n, vector<int> &dp)
    {

        if (n == 0)
        {
            return 0;
        }

        if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
        {
            return 1;
        }

        if (dp[n] != INT_MAX)
        {
            return dp[n];
        }

        for (int i = 1; i * i < n; i++)
        {
            dp[n] = min(dp[n], solve(n - i * i, dp) + 1);
        }

        return dp[n];
    }

public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        return solve(n, dp);
    }
};

int main()
{

    int n;

    cin >> n;

    Solution s;

    cout << s.numSquares(n) << endl;

        return 0;
}