// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int solve(int i, vector<int> &arr, int buy, int cap, vector<vector<vector<int>>> &dp)
{
    if (cap == 0 || i == arr.size())
    {
        return 0;
    }

    if (dp[i][buy][cap] != -1)
    {
        return dp[i][buy][cap];
    }

    if (buy)
    {
        dp[i][buy][cap] = max(-arr[i] + solve(i + 1, arr, 0, cap, dp),
                              solve(i + 1, arr, 1, cap, dp));
    }
    else
    {
        dp[i][buy][cap] = max(arr[i] + solve(i + 1, arr, 1, cap - 1, dp),
                              solve(i + 1, arr, 0, cap, dp));
    }

    return dp[i][buy][cap];
}

int maxProfit(vector<int> &arr)
{
    // Write your code here..
    int n = arr.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    return solve(0, arr, 1, 2, dp);
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        cout << maxProfit(price) << endl;
    }
}

// } Driver Code Ends