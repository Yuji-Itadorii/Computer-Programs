// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int arr[], int n, int k)
    {
        // Write Your Code here
        vector<int> ans;

        sort(arr, arr + n);
        int count = arr[0];
        int size = n - k;

        for (int i = 1; i < size; i++)
        {
            count += arr[i];
            size = size - k;
        }
        ans.push_back(count);

        count = arr[n - 1];
        size = k - 1;

        for (int i = n - 2; i > size; i--)
        {
            count += arr[i];
            size = size + k;
        }

        ans.push_back(count);

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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends