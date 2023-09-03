// https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long maxi = 0;
        long long sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }
        if (mp.size() >= m)
            maxi = max(maxi, sum);
        int size = 0;
        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i];
            sum -= nums[i - k];
            mp[nums[i - k]]--;
            mp[nums[i]]++;

            if (mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);

            if (mp.size() >= m)
            {
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << s.maxSum(nums, m, k) << endl;
    }
    return 0;
}