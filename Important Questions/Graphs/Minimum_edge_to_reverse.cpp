// https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 0}); // for original
            adj[v].push_back({u, 1}); // for reversing which we put
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});
        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            for (auto v : adj[node])
            {
                int d2 = d + v.second;
                int node2 = v.first;

                if (dist[node2] > d2)
                {
                    dist[node2] = d2;
                    pq.push({d2, node2});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
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
        vector<vector<int>> edges(m, vector<int>(2));
        for (auto &j : edges)
            for (auto &i : j)
                cin >> i;
        int src, dst;
        cin >> src >> dst;
        Solution s;
        cout << s.minimumEdgeReversal(edges, n, src, dst) << endl;
    }
    return 0;
}
// } Driver Code Ends