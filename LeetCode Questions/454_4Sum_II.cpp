// https://leetcode.com/problems/4sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int n = nums1.size();
        unordered_map<int, int> s1, s2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums1[i] + nums2[j];
                s1[sum]++;
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums3[i] + nums4[j];
                if (s1.count(0 - sum))
                {
                    count += s1[0 - sum];
                }
            }
        }

        return count;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {-2, -1};
        vector<int> nums3 = {-1, 2};
        vector<int> nums4 = {0, 2};
        cout << ob.fourSumCount(nums1, nums2, nums3, nums4) << endl;
        }
    return 0;
}