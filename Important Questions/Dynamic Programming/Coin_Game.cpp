// https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findWinner(int n, int x, int y)
    {
        // Your code goes here
        int dp[n + 1];

        // Initial values
        dp[0] = false;
        dp[1] = true;

        // Computing other values.
        for (int i = 2; i <= n; i++)
        {

            // If A losses any of i-1 or i-x
            // or i-y game then he will
            // definitely win game i
            if (i - 1 >= 0 and !dp[i - 1])
                dp[i] = true;
            else if (i - x >= 0 and !dp[i - x])
                dp[i] = true;
            else if (i - y >= 0 and !dp[i - y])
                dp[i] = true;

            // Else A loses game.
            else
                dp[i] = false;
        }

        // If dp[n] is true then A will
        // game otherwise  he losses
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        Solution ob;
        cout << ob.findWinner(n, x, y);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends