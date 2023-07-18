// https://takeuforward.org/data-structure/topological-sort-using-dfs/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    void dfs(vector<int> adj[], int sr, stack<int> &s, vector<bool> &vis)
    {
        vis[sr] = true;

        for (auto v : adj[sr])
        {
            if (vis[v] == false)
            {
                dfs(adj, v, s, vis);
            }
        }

        s.push(sr);
    }

    vector<int> topoSort(int N, vector<int> adj[])
    {
        // code here
        stack<int> s;
        vector<bool> vis(N, false);

        for (int i = 0; i < N; i++)
        {
            if (vis[i] == false)
                dfs(adj, i, s, vis);
        }

        vector<int> res;

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends