// https://leetcode.com/problems/product-of-array-except-self/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        // for(auto x : suffix) cout<<x<<" ";

        vector<int> res(n);
        res[0] = suffix[1];
        res[n - 1] = prefix[n - 2];

        for (int i = 1; i < n - 1; i++)
        {
            res[i] = prefix[i - 1] * suffix[i + 1];
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        Solution ob;
        vector<int> ans = ob.productExceptSelf(nums);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        }
    return 0;
}