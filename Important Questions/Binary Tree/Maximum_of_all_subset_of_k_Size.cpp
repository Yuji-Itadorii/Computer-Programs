// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int, int>> p;

        for (int i = 0; i < k; i++)
        {
            p.push({arr[i], i});
        }

        vector<int> res;

        res.push_back(p.top().first);

        for (int i = k; i < n; i++)
        {
            p.push({arr[i], i});

            while (p.top().second <= i - k)
            {
                p.pop();
            }

            res.push_back(p.top().first);
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

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends