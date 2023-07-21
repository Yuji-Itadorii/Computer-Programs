// https://practice.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

//{ Driver Code Starts
// Initial Template for C++

// The longest path problem for a general graph is not as easy as the shortest path problem because the longest path problem doesn’t have optimal substructure property. In fact, the Longest Path problem is NP-Hard for a general graph. However, the longest path problem has a linear time solution for directed acyclic graphs. The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting.

// Following is complete algorithm for finding longest distances.

// Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite.
// Create a topological order of all vertices.
// Do following for every vertex u in topological order.
// ..Do following for every adjacent vertex v of u
// ……if (dist[v] < dist[u] + weight(u, v))
// ………dist[v] = dist[u] + weight(u, v)

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &s)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i.first])
                dfs(i.first, adj, vis, s);
        }
        s.push(node);
    }

public:
    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
    {
        // code here
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < e; i++)
        {
            int x = edges[i][0], y = edges[i][1], z = edges[i][2];
            adj[x].push_back({y, z});
        }

        stack<int> s;
        vector<int> visited(v);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                dfs(i, adj, visited, s);
        }

        vector<int> distance(v, INT_MIN);
        distance[src] = 0;

        while (!s.empty())
        {
            auto p = s.top();
            s.pop();

            for (auto i : adj[p])
            {
                int node = i.first, dist = i.second;

                if (distance[p] == INT_MIN)
                    continue;

                if (distance[p] + dist > distance[node])
                    distance[node] = distance[p] + dist;
            }
        }

        return distance;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int v, e;
        cin >> v >> e;

        int src;
        cin >> src;
        vector<vector<int>> edges(e, vector<int>(3));
        for (auto &j : edges)
            cin >> j[0] >> j[1] >> j[2];

        Solution s;
        vector<int> ans = s.maximumDistance(edges, v, e, src);
        for (auto j : ans)
        {
            if (j == INT_MIN)
                cout << "INF ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends