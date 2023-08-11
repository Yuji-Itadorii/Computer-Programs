// https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    vector<vector<int>> dp;

    int solve(int n, vector<int> &coins, int sum)
    {

        if (n == 0)
        {
            return 0;
        }

        if (sum == 0)
        {
            return 1;
        }

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        if (coins[n - 1] > sum)
        {
            dp[n][sum] = solve(n - 1, coins, sum);
            return dp[n][sum];
        }

        dp[n][sum] = solve(n, coins, sum - coins[n - 1]) +
                     solve(n - 1, coins, sum);

        return dp[n][sum];
    }

public:
    int change(int sum, vector<int> &coins)
    {
        int n = coins.size();
        if (sum == 0)
        {
            return 1;
        }
        if (n == 0)
            return 0;

        dp.resize(n + 2, vector<int>(sum + 2, -1));
        dp[n][sum] = solve(n, coins, sum);
        return dp[n][sum];
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        int sum;
        cin >> sum;
        cout << s.change(sum, coins) << endl;
    }
    return 0;
}