// https://leetcode.com/problems/sorting-three-groups/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] >= nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;

        int lis = *max_element(dp.begin(), dp.end());
        cout << lis;

        return nums.size() - lis;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<int> nums;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        cout << s.minimumOperations(nums) << endl;
    }
    return 0;
}