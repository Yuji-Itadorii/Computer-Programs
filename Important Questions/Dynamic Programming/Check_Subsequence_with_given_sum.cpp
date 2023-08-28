// https://practice.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    bool backtrack(int index, int n, vector<int> &arr, int k, int curr_sum, vector<vector<int>> &dp)
    {
        if (curr_sum > k)
            return false;
        if (curr_sum == k)
            return true;
        if (index == n)
            if (curr_sum != k)
                return false;

        if (dp[index][curr_sum] != -1)
            return dp[index][curr_sum];

        // picking
        bool take = false, nottake = false;
        curr_sum += arr[index];
        take = (backtrack(index + 1, n, arr, k, curr_sum, dp));

        // not picking
        curr_sum -= arr[index];
        nottake = (backtrack(index + 1, n, arr, k, curr_sum, dp));

        return dp[index][curr_sum] = (take || nottake);
    }

public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int curr_sum = 0;
        bool result = backtrack(0, n, arr, k, curr_sum, dp);
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}
// } Driver Code Ends