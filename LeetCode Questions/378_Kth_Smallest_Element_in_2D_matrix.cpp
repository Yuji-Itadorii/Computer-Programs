// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        priority_queue<int> maxHeap;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                maxHeap.push(matrix[r][c]);
                if (maxHeap.size() > k)
                    maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n, k;
        cin >> n >> k;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << ob.kthSmallest(matrix, k) << endl;
    }
    return 0;
}