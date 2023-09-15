// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool solve(int n, int arr[], int index, int sum, vector<vector<int>> &dp)
    {
        if (sum < 0)
        {
            return 0;
        }

        if (index >= n)
        {
            if (sum == 0)
                return 1;
            return 0;
        }

        if (dp[index][sum] != -1)
        {
            return dp[index][sum];
        }

        return dp[index][sum] = solve(n, arr, index + 1, sum, dp) || solve(n, arr, index + 1, sum - arr[index], dp);
    }

public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum & 1)
            return 0;
        else
        {
            vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
            return solve(n, arr, 0, sum / 2, dp);
        }
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