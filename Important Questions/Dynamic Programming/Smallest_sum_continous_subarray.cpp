// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int smallestSumSubarray(vector<int> &nums)
    {
        // Code here
        int n = nums.size();
        int sum = 0, ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i]; // Add the sum
            sum = min(sum, nums[i]);

            ans = min(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;
    }
}
// } Driver Code Ends