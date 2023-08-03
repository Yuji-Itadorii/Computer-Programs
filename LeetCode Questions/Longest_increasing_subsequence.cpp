// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &a)
    {
        int n = a.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int index = lower_bound(res.begin(), res.end(), a[i]) - res.begin();

            // cout<<index<<endl;

            if (index == res.size())
            {
                res.push_back(a[i]);
            }
            else
            {
                res[index] = a[i];
            }
            // print(res);
        }
        return res.size();
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    Solution s;
    cout << s.lengthOfLIS(nums) << endl;

    return 0;
}