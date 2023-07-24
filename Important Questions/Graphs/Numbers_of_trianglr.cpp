// https://practice.geeksforgeeks.org/problems/number-of-triangles/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int numberOfTriangles(vector<vector<int>> &g, int V)
    {
        // code it up
        int count_Triangle = 0;
        if (V < 3)
            return 0;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                for (int k = 0; k < V; k++)
                {
                    // Check the triplet if
                    // it satisfies the condition
                    if (i != j && j != k && k != i && g[i][j] && g[j][k] && g[k][i])
                        count_Triangle++;
                }
            }
        }

        count_Triangle /= 3;

        return count_Triangle;
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
        vector<vector<int>> g(n, vector<int>(n));
        for (auto &j : g)
            for (auto &i : j)
                cin >> i;
        Solution s;
        cout << s.numberOfTriangles(g, n) << endl;
    }
    return 0;
}
// } Driver Code Ends