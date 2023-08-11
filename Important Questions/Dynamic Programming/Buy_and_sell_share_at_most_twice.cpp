// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int maxProfit(vector<int> &arr)
{
    // Write your code here..
    int n = arr.size();
    int ma = arr[n - 1];
    int mi = arr[0];
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > ma)
            ma = arr[i];
        dp[i] = max(dp[i + 1], ma - arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mi)
            mi = arr[i];
        dp[i] = max(dp[i - 1], dp[i] + (arr[i] - mi));
    }

    return dp[n - 1];
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