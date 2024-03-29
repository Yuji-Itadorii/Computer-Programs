// https://www.geeksforgeeks.org/count-ways-to-obtain-given-sum-by-repeated-throws-of-a-dice/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int mod = 1e9 + 7;

    long long solve(int n, int k, int target, vector<vector<long long>> &dp)
    {
        if (n == 0)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (target <= 0)
            return 0;

        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        long long count = 0;

        for (int i = 1; i <= k; i++)
        {
            if (target >= i)
            {
                count += solve(n - 1, k, target - i, dp);
            }
        }

        dp[n][target] = count;

        return dp[n][target];
    }

    long long noOfWays(int M, int N, int X)
    {
        // code here
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        return solve(N, M, X, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends