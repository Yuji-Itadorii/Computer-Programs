// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }

        if (n == 0)
        {
            return false;
        }

        if (dp[sum][n - 1] != -1)
        {
            return dp[sum][n - 1];
        }

        if (arr[n - 1] > sum)
        {
            return dp[sum][n - 1] = solve(arr, n - 1, sum, dp);
        }

        return dp[sum][n - 1] = solve(arr, n - 1, sum, dp) || solve(arr, n - 1, sum - arr[n - 1], dp);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));

        return solve(arr, n, sum, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends