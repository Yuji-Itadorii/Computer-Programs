// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> G[], int n, int s, vector<bool> &vis, int c, int d)
    {
        vis[s] = true;

        for (auto v : G[s])
        {
            if (s == c && v == d || s == d && v == c)
            {
                continue;
            }
            if (vis[v] == false)
            {
                dfs(G, n, v, vis, c, d);
            }
        }
    }

    int isBridge(int n, vector<int> G[], int c, int d)
    {

        vector<bool> visited(n, false);

        dfs(G, n, c, visited, c, d);

        return visited[d] == 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends