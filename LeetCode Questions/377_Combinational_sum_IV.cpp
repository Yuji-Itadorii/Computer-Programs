// https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
    // unordered_map<string , int> memo;
    int solve(int i, int target, vector<int> &nums, vector<int> &dp)
    {

        if (0 == target)
        {
            return 1;
        }

        if (0 > target)
        {
            return 0;
        }

        if (dp[target] != -1)
            return dp[target];

        if (i >= nums.size())
        {
            return 0;
        }

        int ans = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            ans += solve(j, target - nums[j], nums, dp);
        }

        return dp[target] = ans;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(0, target, nums, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << ob.combinationSum4(nums, target) << "\n";
        }
    return 0;
}