// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void add_edge(vector<int> adj[], int u, int v, vector<int> &in)
    {
        adj[u].push_back(v);
        in[v]++;
    }

    bool isPossible(int N, int P, vector<pair<int, int>> &edges)
    {
        // Code here
        vector<int> adj[N];
        vector<int> in(N, 0);
        for (int i = 0; i < P; i++)
        {
            add_edge(adj, edges[i].first, edges[i].second, in);
        }

        queue<int> q;
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;

            for (auto v : adj[u])
            {
                in[v]--;
                if (in[v] == 0)
                {

                    q.push(v);
                }
            }
        }

        return count == N;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends