// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(int i, int arr[], int n, int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0 || i == n)
        {
            return 0;
        }

        if (dp[i][buy][cap] != -1)
        {
            return dp[i][buy][cap];
        }

        if (buy)
        {
            dp[i][buy][cap] = max(-arr[i] + solve(i + 1, arr, n, 0, cap, dp),
                                  solve(i + 1, arr, n, 1, cap, dp));
        }
        else
        {
            dp[i][buy][cap] = max(arr[i] + solve(i + 1, arr, n, 1, cap - 1, dp),
                                  solve(i + 1, arr, n, 0, cap, dp));
        }

        return dp[i][buy][cap];
    }

public:
    int maxProfit(int K, int n, int arr[])
    {
        // code here
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(K + 1, -1)));
        return solve(0, arr, n, 1, K, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends