// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return 0;

        long long count = 0, prev = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            int noOfTime = nums[i] / prev;
            if ((nums[i]) % prev != 0)
            {
                noOfTime++;
                prev = nums[i] / noOfTime;
            }
            count += noOfTime - 1;
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << ob.minimumReplacement(nums) << endl;
    }
    return 0;
}