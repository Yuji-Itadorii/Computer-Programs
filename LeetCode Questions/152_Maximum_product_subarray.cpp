// https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int minProduct = 1;
        int maxProduct = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(maxProduct * nums[i], nums[i]);
            minProduct = min(minProduct * nums[i], nums[i]);
            ans = max(ans, maxProduct);
        }
        return ans;
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
        {
            cin >> nums[i];
        }
        cout << ob.maxProduct(nums) << endl;
    }
    return 0;
}