// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(int i, int j, int n, vector<vector<int>> &m)
    {
        if ((i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0))
        {
            return false;
        }
        return true;
    }

    void solve(int i, int j, vector<vector<int>> &m,
               int n, vector<string> &ans, string s)
    {

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            s = "";
            return;
        }

        if (isSafe(i, j, n, m))
        {
            m[i][j] = 0;
            solve(i + 1, j, m, n, ans, s + "D");
            solve(i, j - 1, m, n, ans, s + "L");
            solve(i, j + 1, m, n, ans, s + "R");
            solve(i - 1, j, m, n, ans, s + "U");
            m[i][j] = 1;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        {
            return {};
        }

        string s = "";
        vector<string> ans;
        solve(0, 0, m, n, ans, s);
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends