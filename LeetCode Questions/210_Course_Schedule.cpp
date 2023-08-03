// https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &s, vector<int> &rest)
    {
        vis[node] = 1;
        rest[node] = true;

        for (auto v : adj[node])
        {
            if (vis[v] == 0 && dfs(v, vis, adj, s, rest))
            {
                return true;
            }
            else if (rest[v] == true)
            {
                return true;
            }
        }

        rest[node] = false;
        s.push(node);

        return false;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[n];

        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        stack<int> s;
        vector<int> vis(n, 0), res, rest(n, 0);
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, vis, adj, s, rest))
                {
                    flag = true;
                }
            }
        }

        if (flag)
        {
            return {};
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> res = s.findOrder(4, prerequisites);

    for (auto it : res)
    {
        cout << it << " ";
    }

        return 0;
}