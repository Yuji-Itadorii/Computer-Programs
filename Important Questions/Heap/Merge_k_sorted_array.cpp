// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        // code here
        vector<int> res;
        vector<int> idx(K, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < K; i++)
        {
            pq.push(make_pair(arr[i][0], i));
        }

        while (pq.empty() == false)
        {
            pair<int, int> x = pq.top();
            pq.pop();

            res.push_back(x.first);

            if (idx[x.second] + 1 < arr[x.second].size())
            {
                pq.push({arr[x.second][idx[x.second] + 1], x.second});
            }

            idx[x.second] += 1;
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
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends