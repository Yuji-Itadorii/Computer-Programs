// https://leetcode.com/problems/last-stone-weight-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    int dp[35][3005];

    int solve(int n, vector<int> &arr, int sum1, int sum2)
    {

        if (n == 0)
        {
            return abs(sum1 - sum2);
        }

        if (sum1 == 0)
        {
            return sum2;
        }

        if (sum2 == 0)
        {
            return sum1;
        }

        int sum = min(sum1 - arr[n - 1], sum2 - arr[n - 1]);

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        int opt1 = solve(n - 1, arr, sum1 - arr[n - 1], sum2);
        int opt2 = solve(n - 1, arr, sum1, sum2 - arr[n - 1]);

        return dp[n][sum] = min(opt1, opt2);
    }

public:
    int lastStoneWeightII(vector<int> &stones)
    {

        int n = stones.size();
        long long sum = 0;
        memset(dp, -1, sizeof(dp));
        sum = accumulate(stones.begin(), stones.end(), sum);
        // cout<<sum;

        return solve(n, stones, sum, sum);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}