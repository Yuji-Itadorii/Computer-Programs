// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        // code here

        if (M > N || S > 6 && 6 * N < 7 * M)
        {
            return -1;
        }
        else
        {
            int p = S * M / N;

            if ((S * M) % N)
            {
                p++;
            }

            return p;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends