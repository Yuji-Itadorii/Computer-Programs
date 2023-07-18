// https://practice.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void add_edge(vector<int> adj[], int u, int v, vector<int> &in)
    {
        adj[u].push_back(v);
        in[v]++;
    }

    vector<int> minimumTime(int N, vector<vector<int>> &edges, int m)
    {
        // code here
        vector<int> adj[N];
        vector<int> in(N, 0);
        for (int i = 0; i < m; i++)
        {
            add_edge(adj, edges[i][0] - 1, edges[i][1] - 1, in);
        }

        queue<int> q;
        vector<int> res(N, 1);

        for (int i = 0; i < N; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                in[v]--;
                if (in[v] == 0)
                {
                    res[v] = res[u] + 1;
                    q.push(v);
                }
            }
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
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends