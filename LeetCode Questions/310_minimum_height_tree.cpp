// https://leetcode.com/problems/minimum-height-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];

        if (n == 0)
            return {};
        if (n == 1)
            return {0};
        vector<int> res;
        vector<int> degrees(n, 0);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degrees[it[1]]++;
            degrees[it[0]]++;
        }

        queue<int> queue;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1) // adding all the leave nodes
                queue.push(i);
        }

        while (!queue.empty())
        {
            res.clear(); // clear vector before we start traversing level by level.
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int cur = queue.front();
                queue.pop();
                res.push_back(cur);
                for (auto &neighbor : adj[cur])
                {
                    degrees[neighbor]--;        // removing current leave nodes
                    if (degrees[neighbor] == 1) // adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> res = s.findMinHeightTrees(4, edges);
    for (auto it : res)
        cout << it << " ";

        return 0;
}