// https://leetcode.com/problems/3sum/solutions/1462423/c-both-two-pointers-and-hashmap-approach-explained/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;
        set<vector<int>> st;
        int i = 0;
        while (i < n)
        {
            int k = n - 1;
            int j = i + 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }

        for (auto x : st)
        {
            res.push_back(x);
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
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> ans = ob.threeSum(nums);
        for (auto x : ans)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
        }
    return 0;
}