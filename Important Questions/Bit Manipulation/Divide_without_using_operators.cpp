// https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        // code here
        long long quotient = 0;
        long long temp = 0;
        long long sign = (dividend >= 0) ^ (divisor >= 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        for (int i = 31; i >= 0; i--)
        {
            if (temp + (divisor << i) <= dividend)
            {
                temp += divisor << i;
                quotient += (1LL << i);
            }
        }
        return quotient * sign;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.divide(a, b) << "\n";
    }

    return 0;
}

// } Driver Code Ends