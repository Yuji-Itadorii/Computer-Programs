// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kthLargest(vector<int> &arr, int n, int k)
    {

        priority_queue<int, vector<int>, greater<int>> p;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                p.push(sum);
                if (p.size() > k)
                {
                    p.pop();
                }
            }
        }

        return p.top();
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends