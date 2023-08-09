// https://leetcode.com/problems/longest-consecutive-sequence/submissions/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = true;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i] - 1) > 0)
            {
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map[nums[i]] == true)
            {
                int j = 0;
                int count = 0;
                while (map.count(nums[i] + j) > 0)
                {
                    j++;
                    count++;
                }
                if (count > maxlen)
                {
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        Solution ob;
        cout << ob.longestConsecutive(nums) << endl;
    }
    return 0;
}