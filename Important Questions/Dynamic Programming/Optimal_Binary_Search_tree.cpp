// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int sum(int freq[], int i, int j)
    {
        int s = 0;
        for (int k = i; k <= j; k++)
            s += freq[k];
        return s;
    }

public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        int dp[n][n];

        // for calculating prefix sum to get the sum of frequencies in a range
        int prefix_sum[n];
        prefix_sum[0] = freq[0];

        for (int i = 1; i < n; i++)
            prefix_sum[i] = freq[i] + prefix_sum[i - 1];

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0) // for single node
                {
                    dp[i][j] = freq[i];
                }
                else if (gap == 1) // for two nodes
                {
                    int f1 = freq[i];
                    int f2 = freq[j];
                    dp[i][j] = min(f1 + 2 * f2, f2 + 2 * f1);
                }
                else
                {
                    int min = INT_MAX;
                    // sum of frequencies in range [i,j]
                    int freq_sum = prefix_sum[j] - (i == 0 ? 0 : prefix_sum[i - 1]);

                    for (int k = i; k <= j; k++) // for every node as root
                    {
                        int left = k == i ? 0 : dp[i][k - 1];
                        int right = k == j ? 0 : dp[k + 1][j];

                        if (left + right + freq_sum < min)
                        {
                            min = left + right + freq_sum;
                        }
                    }

                    dp[i][j] = min; // min cost for range [i,j]
                }
            }
        }

        return dp[0][n - 1]; // min cost for range [0,n-1]
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
        int keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        int freq[n];
        for (int i = 0; i < n; i++)
            cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
}
// } Driver Code Ends