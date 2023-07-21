// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Idea:- Check if the graph can be colored with 2 colors such that no 2 adjacent nodes have same color.

// Any graph with even cycle is a bipartite graph.

// Any graph with odd cycle is not a bipartite graph.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> col(V, -1);

        // queue for BFS storing {vertex , colour}
        queue<pair<int, int>> q;

        for (int i = 0; i < V; i++)
        {

            // if not coloured
            if (col[i] == -1)
            {

                // colouring with 0 i.e. red
                q.push({i, 0});
                col[i] = 0;

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    // current vertex
                    int v = p.first;
                    // colour of current vertex
                    int c = p.second;

                    // traversing vertexes connected to current vertex
                    for (int j : adj[v])
                    {

                        // if already coloured with parent vertex color
                        // then bipartite graph is not possible
                        if (col[j] == c)
                            return 0;

                        // if uncoloured
                        if (col[j] == -1)
                        {
                            // colouring with opposite color to that of parent
                            col[j] = (c) ? 0 : 1;
                            q.push({j, col[j]});
                        }
                    }
                }
            }
        }
        // if all vertexes are coloured such that
        // no two connected vertex have same colours
        return 1;
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
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends