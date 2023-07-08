// https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a + n);

        long long int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0 && k > 0)
            {
                a[i] = abs(a[i]);
                k--;
            }
        }

        // cout<<"k -> "<<k<<endl;

        long long int min_positive = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            ans += a[i];
            min_positive = min(min_positive, a[i]);
        }

        if (k % 2 != 0)
        {
            ans -= 2 * min_positive;
        }

        return ans;
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
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends