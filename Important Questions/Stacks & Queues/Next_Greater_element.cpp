// https://www.geeksforgeeks.org/next-greater-element/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> v(n, -1);
        long long mx = arr[n - 1];
        stack<long long> s;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] > arr[i])
            {
                v[i] = arr[i + 1];
            }
            else
            {
                if (v[i + 1] > arr[i])
                {
                    v[i] = v[i + 1];
                }
                else if (mx > arr[i])
                {
                    int k = i + 1;
                    while (arr[k] <= arr[i])
                    {
                        k++;
                    }
                    v[i] = arr[k];
                }
                else
                {
                    v[i] = -1;
                }
            }

            mx = max(mx, arr[i]);
        }

        return v;
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends