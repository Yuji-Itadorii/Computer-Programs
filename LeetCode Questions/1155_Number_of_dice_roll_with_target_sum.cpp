// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mod = 1e9 + 7;

    int helper(int dices, int faces, int target, vector<vector<int>> &dp)
    {

        if (dices == 0)
        {
            if (target == 0)
                return 1;
            return 0;
        }

        if (target <= 0)
            return 0;

        if (dp[dices][target] != -1)
        {
            return dp[dices][target];
        }

        size_t count = 0;

        for (int i = 1; i <= faces; i++)
        {
            if (i <= target)
            {
                count += helper(dices - 1, faces, target - i, dp);
                count = count % mod;
            }
        }
        dp[dices][target] = count;
        return dp[dices][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }
};

int main()
{

    Solution s;
    cout << s.numRollsToTarget(30, 30, 500) << endl;
    return 0;
}