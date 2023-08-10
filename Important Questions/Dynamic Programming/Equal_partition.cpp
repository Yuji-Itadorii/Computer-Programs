// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool solve(int n, int arr[], int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }

        if (n == 0)
        {
            return false;
        }

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        return dp[n][sum] = solve(n - 1, arr, sum, dp) || solve(n - 1, arr, sum - arr[n - 1], dp);
    }

public:
    int equalPartition(int n, int arr[])
    {
        // code here
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if (sum % 2 == 1)
        {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return solve(n, arr, sum / 2, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends