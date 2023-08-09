// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int solveSpace1D(int arr[], int n)
    {
        vector<int> curr(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            curr[i] = arr[i];

            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                    curr[i] = max(curr[i], curr[j] + arr[i]);
            }
            ans = max(ans, curr[i]);
        }
        return ans;
    }

public:
    int maxSumIS(int arr[], int n)
    {
        return solveSpace1D(arr, n);
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

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends