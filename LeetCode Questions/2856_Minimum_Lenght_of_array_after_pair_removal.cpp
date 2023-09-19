// https://leetcode.com/problems/minimum-array-length-after-pair-removals/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minLengthAfterRemovals(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        int maxi = 0;
        for (auto it : mp)
        {
            maxi = max(maxi, it.second);
        }
        if (maxi <= n / 2)
        {
            if (n % 2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 2 * maxi - n;
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
        cout << ob.minLengthAfterRemovals(nums) << endl;
    }
    return 0;
}