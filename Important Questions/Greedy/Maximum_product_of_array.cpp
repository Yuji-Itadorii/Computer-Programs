// https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int mod = pow(10, 9) + 7;

    long long int findMaxProduct(vector<int> &a, int n)
    {
        // Write your code here
        if (n == 1)
            return a[0];

        // Find count of negative numbers, count
        // of zeros, negative number
        // with least absolute value
        // and product of non-zero numbers
        long long int max_neg = INT_MIN;
        long long int count_neg = 0, count_zero = 0;
        long long int prod = 1;
        for (int i = 0; i < n; i++)
        {

            // If number is 0, we don't
            // multiply it with product.
            if (a[i] == 0)
            {
                count_zero++;
                continue;
            }

            // Count negatives and keep
            // track of negative number
            // with least absolute value
            if (a[i] < 0)
            {
                count_neg++;
                max_neg = max(max_neg, (long long int)a[i]);
            }

            if (a[i] != 0)
            {
                prod = (prod * a[i]) % mod;
            }
        }

        // If there are all zeros
        if (count_zero == n)
            return 0;

        // If there are odd number of
        // negative numbers
        if (count_neg & 1)
        {

            // Exceptional case: There is only
            // negative and all other are zeros
            if (count_neg == 1 &&
                count_zero > 0 &&
                count_zero + count_neg == n)
                return 0;

            // Otherwise result is product of
            // all non-zeros divided by
            // negative number with
            // least absolute value
            prod = (prod / max_neg) % mod;
        }

        return prod;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends