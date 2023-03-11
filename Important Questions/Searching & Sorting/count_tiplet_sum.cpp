// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Your code goes here
        sort(arr, arr + n);

        long long count = 0;
        for (int x = 0; x < n - 2; x++)
        {
            int i = x + 1, j = n - 1;
            while (i < j)
            {
                long long s = arr[i] + arr[j] + arr[x];
                // cout<<s<<endl;
                if (s < sum)
                {
                    count += j - i;
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }

        return count;
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
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends