// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs_visit(vector<int> G[], int s, vector<bool> &vis, vector<int> &ans)
    {
        vis[s] = true;

        // cout << s << " ";
        ans.push_back(s);

        for (auto v : G[s])
        {
            if (vis[v] == false)
            {
                dfs_visit(G, v, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int n, vector<int> G[])
    {
        // Code here
        vector<bool> vis(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                dfs_visit(G, i, vis, ans);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends