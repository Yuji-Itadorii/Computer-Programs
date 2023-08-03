// https://leetcode.com/problems/predict-the-winner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int opt1 = arr[i] + min(solve(i + 1, j - 1, arr, dp), solve(i + 2, j, arr, dp));
        int opt2 = arr[j] + min(solve(i + 1, j - 1, arr, dp), solve(i, j - 2, arr, dp));

        return dp[i][j] = max(opt1, opt2);
    }

    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        long long sum1 = solve(0, n - 1, nums, dp);
        long long sum2 = sum - sum1;

        return sum1 >= sum2;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 2};
    cout << s.predictTheWinner(nums) << endl;

        return 0;
}