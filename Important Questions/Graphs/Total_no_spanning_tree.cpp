// https://practice.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int determinantOfMatrix(vector<vector<int>> matrix)
    {
        int det = 0;
        if (matrix.size() == 1)
            return matrix[0][0];
        else if (matrix.size() == 2)
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        else
        {
            for (int p = 0; p < matrix[0].size(); p++)
            {
                vector<vector<int>> temp;
                for (int i = 1; i < matrix.size(); i++)
                {
                    vector<int> row;
                    for (int j = 0; j < matrix[0].size(); j++)
                    {
                        if (p != j)
                            row.push_back(matrix[i][j]);
                    }
                    if (row.size() > 0)
                        temp.push_back(row);
                }
                det = det + matrix[0][p] * pow(-1, p) * determinantOfMatrix(temp);
            }
            return det;
        }
    }

    int countSpanningTrees(vector<vector<int>> &matrix, int n, int m)
    {
        // Write your code here
        vector<int> degree(n, 0);
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        for (auto it : matrix)
        {
            adjMatrix[it[0]][it[1]] = 1;
            adjMatrix[it[1]][it[0]] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMatrix[i][j] == 1)
                {

                    degree[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            adjMatrix[i][i] = degree[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i != j) and adjMatrix[i][j] == 1)
                {
                    adjMatrix[i][j] = -1;
                }
            }
        }

        vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                submatrix[i - 1][j - 1] = adjMatrix[i][j];
            }
        }

        return determinantOfMatrix(submatrix);
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
        vector<vector<int>> graph(m, vector<int>(2, 0));
        for (int i = 0; i < m; i++)
        {
            cin >> graph[i][0] >> graph[i][1];
        }
        Solution ob;
        int ans = ob.countSpanningTrees(graph, n, m);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends