// https://www.geeksforgeeks.org/permutation-coefficient/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long mod = 1e9 + 7;

    int permutationCoeff(int n, int k)
    {
        // Code here
        long long res = 1;
        for (long long i = n; i > (n - k); i--)
        {
            res = (res * i) % mod;
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        int ans = ob.permutationCoeff(n, k);
        cout << ans << endl;
    }
}
// } Driver Code Ends