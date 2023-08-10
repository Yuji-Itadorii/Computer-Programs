// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int AlternatingSolution(vector<int> &nums)
    {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(down, up);
    }

public:
    int AlternatingaMaxLength(vector<int> &a)
    {
        // Code here

        //  return AlternatingSolution(nums);
        int n = a.size();
        int dp[n][2];
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        int res = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                    dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
                if (a[i] < a[j])
                    dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
            }
            res = max({res, dp[i][0], dp[i][1]});
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends