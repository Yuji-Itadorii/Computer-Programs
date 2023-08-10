// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (arr[0] >= n)
        {
            return 1;
        }
        if (arr[0] == 0)
        {
            return -1;
        }
        if (n <= 1)
        {
            return 0;
        }

        // Your code here
        int res = 1;
        int maxrange = arr[0];
        int step = arr[0];
        for (int i = 1; i < n; i++)
        {

            if (i == n - 1)
                return res;
            maxrange = max(maxrange, i + arr[i]);
            step--;
            if (step == 0)
            {
                res++;
                if (i >= maxrange)
                    return -1;
                step = maxrange - i;
            }
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
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends