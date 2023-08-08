// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    int func(int l, int p, int q, int r, vector<int> &dp)
    {
        if (l == 0)
            return 0; // Base Case

        if (dp[l] != -1) // If already memoized
            return dp[l];

        int a(INT_MIN), b(INT_MIN),
            c(INT_MIN); // Intitialise a,b,& c with INT_MIN

        if (p <= l) // If Possible to make a cut of length p
            a = func(l - p, p, q, r, dp);

        if (q <= l) // If possible to make a cut of length q
            b = func(l - q, p, q, r, dp);

        if (r <= l) // If possible to make a cut of length r
            c = func(l - r, p, q, r, dp);

        return dp[l] = 1 + max({a, b, c}); // Memoize & return
    }

public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        int ans = func(n, x, y, z, dp);
        if (ans < 0)
            return 0; // If returned answer is negative , that
                      // means cuts are not possible
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
}
// } Driver Code Ends