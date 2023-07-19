// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    struct DSU
    {
        int *parent;
        int *rank;

        DSU(int n)
        {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int i)
        {
            if (parent[i] == i)
            {
                return i;
            }

            return find(parent[i]);
        }

        void Union(int s1, int s2)
        {
            int x = find(s1);
            int y = find(s2);

            if (parent[x] != parent[y])
            {
                if (rank[x] > rank[y])
                {
                    parent[y] = x;
                }
                else if (rank[x] < rank[y])
                {
                    parent[x] = y;
                }
                else
                {
                    parent[y] = x;
                    rank[x] += 1;
                }
            }
        }
    };

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges; //{wt, {u, v}}
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                edges.push_back({it[1], {i, it[0]}});
        }

        sort(edges.begin(), edges.end());
        int ans = 0;
        struct DSU dsu(V);
        for (auto it : edges)
        {
            if (dsu.find(it.second.first) != dsu.find(it.second.second))
            {
                dsu.Union(it.second.first, it.second.second);
                ans += it.first;
            }
        }
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends