// https://leetcode.com/problems/jump-game/submissions/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        if (nums.size() == 1)
        {
            return true;
        }

        if (nums[0] == 0)
        {
            return false;
        }

        if (nums[0] >= nums.size())
        {
            return true;
        }

        int step = nums[0];
        int max_step = nums[0];
        // int res = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return true;
            }
            max_step = max(max_step, i + nums[i]);
            step--;
            if (step == 0)
            {
                // res++;
                if (i >= max_step)
                {
                    return false;
                }
                step = max_step - i;
            }
        }

        return true;
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
        cout << s.canJump(nums) << endl;
    }
    return 0;
}