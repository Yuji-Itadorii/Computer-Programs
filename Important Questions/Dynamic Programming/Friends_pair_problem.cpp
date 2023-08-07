// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution
{
private:
    long long mod = 1e9 + 7;

public:
    int countFriendsPairings(int n)
    {
        ll first = 1;
        ll second = 2;

        if (n == 1)
            return 1;

        for (int i = 3; i <= n; i++)
        {
            ll a = second % mod;
            ll b = ((i - 1) * (first % mod)) % mod;

            first = second;
            second = (a + b) % mod;
        }

        return second;
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// } Driver Code Ends