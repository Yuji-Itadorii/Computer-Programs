// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

struct Dset
{
    vector<int> parent;
    vector<int> rank;

    Dset(int n)
    {
        parent.resize(n);
        rank.resize(n);

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

        return parent[i] = find(parent[i]);
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

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int GetMST(int n, vector<vector<int>> &edges, int blockedge, int pre_edge = -1)
    {
        Dset uf(n);
        int weight = 0;
        if (pre_edge != -1)
        {
            weight += edges[pre_edge][2];
            uf.Union(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size(); ++i)
        {
            if (i == blockedge)
                continue;
            const auto &edge = edges[i];
            if (uf.find(edge[0]) == uf.find(edge[1]))
                continue;
            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; ++i)
        {
            if (uf.find(i) != uf.find(0))
                return 1e9 + 7;
        }
        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {

        for (int i = 0; i < edges.size(); ++i)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });
        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (origin_mst < GetMST(n, edges, i))
            {
                critical.push_back(edges[i][3]);
            }
            else if (origin_mst == GetMST(n, edges, -1, i))
            {
                non_critical.push_back(edges[i][3]);
            }
        }
        return {critical, non_critical};
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        Solution ob;
        vector<vector<int>> ans = ob.findCriticalAndPseudoCriticalEdges(n, edges);
        cout << ans[0].size() << " " << ans[1].size() << endl;
        }
    return 0;
}