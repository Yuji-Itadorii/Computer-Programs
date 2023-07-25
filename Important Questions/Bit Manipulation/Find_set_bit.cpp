// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int n)
    {
        // code here
        return !n || n & n - 1 ? -1 : log2(n) + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends