// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution
{
public:
    void dfs(vector<int> G[], int n, int s, vector<bool> &vis)
    {
        vis[s] = true;

        for (auto v : G[s])
        {
            if (vis[v] == false)
            {
                dfs(G, n, v, vis);
            }
        }
    }

    void add_edge(vector<int> G[], int u, int v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int makeConnected(int n, vector<vector<int>> &connection)
    {
        int count = 0;
        if (connection.size() < n - 1)
            return -1;

        vector<int> G[n];

        for (int i = 0; i < connection.size(); i++)
        {
            add_edge(G, connection[i][0], connection[i][1]);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                dfs(G, n, i, visited);
                count++;
            }
        }

        return count - 1;
    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}