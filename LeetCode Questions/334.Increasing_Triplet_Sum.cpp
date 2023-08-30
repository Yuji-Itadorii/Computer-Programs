// https://leetcode.com/problems/increasing-triplet-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto num : nums)
        {
            if (num <= a)
                a = num;
            else if (num <= b)
                b = num;
            else
                return true;
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
        Solution ob;
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << ob.increasingTriplet(nums) << endl;
    }
    return 0;
}