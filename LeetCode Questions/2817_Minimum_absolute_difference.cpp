// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums, int x)
    {
        int n = nums.size();
        set<int> st;
        int minm = INT_MAX;
        for (int i = x; i < n; i++)
        {
            st.insert(nums[i - x]);
            auto it = st.lower_bound(nums[i]);
            if (it != st.end())
                minm = min(minm, abs(nums[i] - *(it)));
            if (it != st.begin())
            {
                --it;
                minm = min(minm, abs(nums[i] - *(it)));
            }
        }

        return minm;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        }
    return 0;
}