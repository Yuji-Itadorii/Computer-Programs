// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Note :- Only for directed graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    // Function to find number of strongly connected components in the graph.
    void toposort(stack<int> &st, vector<int> &vis, vector<vector<int>> adj, int src)
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                toposort(st, vis, adj, it);
            }
        }
        st.push(src);
    }

private:
    void revDfs(int node, vector<int> &vis, vector<int> transpose[])
    {
        vis[node] = 1;
        for (auto it : transpose[node])
        {
            if (!vis[it])
            {
                revDfs(it, vis, transpose);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> vis(V, 0);
        stack<int> st;
        // calling toposort for taking the values in the finishing time in the dfs
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                toposort(st, vis, adj, i);
            }
        }
        // making a transpose of the graph (reverseing the edges)
        int count = 0;
        vector<int> transpose[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        // taking the stack and couting the SCC in the graph
        // by normally doing the dfs according to the top node of the stack.
        while (st.empty() == false)
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                count++;
                revDfs(node, vis, transpose);
            }
        }
        return count;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends