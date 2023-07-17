#include <bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> G[], int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

void print_Graph(vector<int> G[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int x : G[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void bfs(vector<int> G[], int n, int s)
{
    queue<int> q;
    q.push(s);

    vector<bool> vis(n + 1, false);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto v : G[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << endl;
}

void dfs_visit(vector<int> G[], int s, vector<bool> &vis)
{
    vis[s] = true;

    cout << s << " ";

    for (auto v : G[s])
    {
        if (vis[v] == false)
        {
            dfs_visit(G, v, vis);
        }
    }
}

void dfs(vector<int> G[], int n)
{
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs_visit(G, i, vis);
        }
    }
}

int main()
{
    int v = 7;

    vector<int> G[v];

    add_Edge(G, 0, 1);
    add_Edge(G, 0, 4);
    add_Edge(G, 1, 2);
    add_Edge(G, 2, 3);
    add_Edge(G, 4, 5);
    add_Edge(G, 4, 6);

    print_Graph(G, v);

    cout << "BFS --> " << endl;
    bfs(G, v, 0);

    cout << "DFS -->" << endl;
    dfs(G, v);
}