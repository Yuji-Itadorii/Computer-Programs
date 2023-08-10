// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[l] == nums[mid] && nums[r] == nums[mid])
            {
                l++;
                r--;
            }
            else if (nums[mid] > nums[r])
            {
                if (nums[mid] > target && target >= nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid] < nums[l])
            {
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                if (nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
        cout << s.search(nums, 0) << endl;
    }
    return 0;
}