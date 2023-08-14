// https://practice.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void solve(vector<vector<int>> matrix, int xs, int ys, int xd, int yd,
               vector<vector<int>> &ans, vector<int> &v)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (xs < 0 || ys < 0 || xs >= n || ys >= m || matrix[xs][ys] == 0)
        {
            return;
        }

        if (xs == xd && ys == yd)
        {
            v.push_back(matrix[xd][yd]);
            ans.push_back(v);
            v.pop_back();
            return;
        }

        v.push_back(matrix[xs][ys]);
        int temp = matrix[xs][ys];
        matrix[xs][ys] = 0;
        // solve(matrix, xs - 1, ys, xd, yd, ans , v);
        solve(matrix, xs + 1, ys, xd, yd, ans, v);
        solve(matrix, xs, ys + 1, xd, yd, ans, v);
        // solve(matrix, xs, ys - 1, xd, yd, ans , v);
        matrix[xs][ys] = temp;
        v.pop_back();
    }

public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        solve(grid, 0, 0, n - 1, m - 1, ans, v);

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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends