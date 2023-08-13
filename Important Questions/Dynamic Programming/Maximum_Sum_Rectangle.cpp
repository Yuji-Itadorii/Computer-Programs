// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int kadans(vector<int> &a)
    {
        int n = a.size();
        int max_so_far = INT_MIN, max_ending = 0;

        for (int i = 0; i < n; i++)
        {
            max_ending += a[i];

            max_so_far = max(max_so_far, max_ending);

            if (max_ending < 0)
            {
                max_ending = 0;
            }
        }

        return max_so_far;
    }

public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {

        int maxSum = INT_MIN;

        for (int cStart = 0; cStart < C; cStart++)
        {
            vector<int> sum(R, 0);
            for (int cEnd = cStart; cEnd < C; cEnd++)
            {
                for (int row = 0; row < R; row++)
                {
                    sum[row] = sum[row] + M[row][cEnd];
                }
                int curMaxSum = kadans(sum);
                maxSum = max(maxSum, curMaxSum);
            }
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends