// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define mod 1000000007

class Solution
{
    long long mod = 1e9 + 7;
    long long int solve(int n, vector<long long> &dp)
    {
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        long long int count = (solve(n - 1, dp) * (2 * n - 1) * n) % mod;
        dp[n] = count;
        return dp[n];
    }

public:
    int countOrders(int n)
    {
        vector<long long> dp(n + 1, -1);
        return solve(n, dp);
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
        cout << s.countOrders(n) << endl;
    }
    return 0;
}