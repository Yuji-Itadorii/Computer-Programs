// https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            res = max(sum, res);

            if (sum < 0)
            {
                sum = 0;
            }
        }

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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << ob.maxSubArray(nums) << endl;
    }
    return 0;
}