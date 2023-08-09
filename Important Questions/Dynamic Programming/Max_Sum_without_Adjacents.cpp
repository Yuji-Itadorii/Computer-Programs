// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findMaxSum(vector<int> &a)
    {
        // Code Here
        int dp[a.size()];
        dp[0] = a[0];
        dp[1] = a[1] + a[0];
        dp[2] = max(max(a[1] + a[2], a[2] + a[0]), a[1]);

        for (int i = 3; i < a.size(); i++)
        {
            int notTakeCurrent = dp[i - 1];
            int take_current_previous = a[i] + a[i - 1] + dp[i - 3];
            int take_current_second_previous = a[i] + dp[i - 2];
            dp[i] = max(max(notTakeCurrent, take_current_previous), take_current_second_previous);
        }
        return dp[a.size() - 1];
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
        int ans = ob.findMaxSum(a);
        cout << ans << endl;
    }
}
// } Driver Code Ends