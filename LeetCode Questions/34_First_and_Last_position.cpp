// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int l = 0, r = nums.size() - 1;
        int a = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            cout << nums[mid];
            if (nums[mid] == target)
            {
                a = mid;
                r = mid - 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        int b = -1;
        l = 0;
        r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                b = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return {a, b};
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        vector<int> ans = s.searchRange(nums, target);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}