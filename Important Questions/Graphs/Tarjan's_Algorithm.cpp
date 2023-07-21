// https://www.geeksforgeeks.org/bridge-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int time[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, time, low, bridges);
                low[node] = min(low[node], low[it]);
                // node -- it
                if (low[it] > time[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int time[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, time, low, bridges);

        return bridges;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(n, connections);
    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}