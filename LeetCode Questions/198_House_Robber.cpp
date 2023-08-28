// https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    int solve(int i, vector<int> &arr, vector<int> &dp)
    {
        if (i >= arr.size())
        {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        dp[i] = max(arr[i] + solve(i + 2, arr, dp), solve(i + 1, arr, dp));

        return dp[i];
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);

        int res = solve(0, nums, dp);
        return res;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << ob.rob(arr) << endl;
        }
    return 0;
}